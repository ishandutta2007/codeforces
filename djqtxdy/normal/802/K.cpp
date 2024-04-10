#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}
const int Maxn=100005;
int dp0[Maxn],dp1[Maxn];
vector<pii > G[Maxn];
bool vis[Maxn];
bool cmp(int x,int y){
	return x>y; 
}
int n,k;
int solve1(int u){
	vis[u]=true;
	vector<int> res;
	for (int i=0;i<G[u].size();i++){
		if (!vis[G[u][i].first]){
			int ans=solve1(G[u][i].first);
			ans+=G[u][i].second;
			res.pb(ans);
		}
	}
	sort(res.begin(),res.end(),cmp);
	int ans=0;
	for (int i=0;i<min(k-1,(int)res.size());i++){
		ans+=res[i];
	}
//	cout<<u<<' '<<ans<<endl;
	return dp0[u]=ans;
}
int solve2(int u){
	vis[u]=true;
	vector<int> res;
	int tot1=0;
	for (int i=0;i<G[u].size();i++){
		if (!vis[G[u][i].first]){
			res.pb(dp0[G[u][i].first]+G[u][i].second);
		}
	}
	if(res.empty()) return dp1[u]=0; 
	sort(res.begin(),res.end(),cmp);
	int last=res[min(k,(int)res.size())-1];
	for (int i=0;i<min(k-1,(int)res.size()-1);i++){
		tot1+=res[i];
	}
//	if (u==0) cout<<tot1<<last<<endl;
	int ans=0;
	for (int i=0;i<G[u].size();i++){
		if (!vis[G[u][i].first]){
			int cur=solve2(G[u][i].first);
			cur+=G[u][i].second;
			cur+=tot1;
			if (dp0[G[u][i].first]+G[u][i].second>last){
				cur+=last;
				cur-=(dp0[G[u][i].first]+G[u][i].second);
			}
			ans=max(ans,cur);
		}
	}
//	cout<<u<<' '<<ans<<endl;
	return dp1[u]=ans;
}
int main(){

	scanf("%d %d",&n,&k);
	for (int i=0;i<n-1;i++){
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		G[u].pb(mp(v,c));
		G[v].pb(mp(u,c));
	}
	solve1(0);
//	cerr<<123<<endl;
	memset(vis,false,sizeof(vis));
	printf("%d\n",solve2(0));
	return 0; 
}