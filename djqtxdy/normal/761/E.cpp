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
//orz mqy
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
const int Maxn=35;
const long long dx[]={0,-1,1,0};
const long long dy[]={1,0,0,-1};
long long resx[Maxn],resy[Maxn];
bool vis[Maxn];
vector<int> G[Maxn];
void solve(int u,LL x,LL y,LL len,int pos){
	//if (u==8) cout<<pos<<endl;
	vis[u]=true;
	resx[u]=x,resy[u]=y;
	for (int i=0,j=0;i<G[u].size();i++,j++){
		int v=G[u][i];
		if (vis[v]){
			j--;
			continue;
		}
		len>>=1;
		if (j==3-pos) j++;
		solve(v,x+len*dx[j],y+len*dy[j],len,j);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i=1;i<=n;i++){
		if ((int)G[i].size()>4){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	long long sb=(LL)1<<50;
	solve(1,0LL,0LL,sb,-1);
	for (int i=1;i<=n;i++){
		printf("%I64d %I64d\n",resx[i],resy[i]);
	}
	return 0;
}