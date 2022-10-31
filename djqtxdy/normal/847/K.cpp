//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
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
#include <assert.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
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

// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=705;
int n,a,b,k,f;
map<string,int> to;
int cost[Maxn][Maxn];
vector<pair<int,int> > t;
int main(){
	scanf("%d %d %d %d %d",&n,&a,&b,&k,&f);
	int cnt=0;
	for (int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		if (!to.count(x)) to[x]=++cnt;
		if (!to.count(y)) to[y]=++cnt;
		t.pb(mp(to[x],to[y]));
	}
	cost[t[0].first][t[0].second]+=a;
	for (int i=1;i<n;i++){
		if (t[i].first==t[i-1].second){
			cost[t[i].first][t[i].second]+=b;
		}
		else{
			cost[t[i].first][t[i].second]+=a;
		}
	}
	int ans=0;
	vector<int> tot;
	for (int i=1;i<=cnt;i++){
		for (int j=i+1;j<=cnt;j++){
			cost[i][j]+=cost[j][i];
			if (cost[i][j]==0) continue;
			ans+=cost[i][j];
			tot.pb(cost[i][j]);
		}
	}
	//cout<<ans<<endl;
	sort(tot.begin(),tot.end());
	reverse(tot.begin(),tot.end());
	for (int i=0;i<min(k,(int)tot.size());i++){
		//cout<<tot[i]<<endl;
		if (tot[i]>f){
			ans-=(tot[i]-f);
		}
	}
	printf("%d\n",ans);
	return 0;
}