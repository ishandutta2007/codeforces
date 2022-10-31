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
const int Maxn=200005;
int ans[Maxn];
int va[Maxn];
vector<int> G[Maxn];
bool vis[Maxn];
int gcd(int x,int y){
	return (y)?gcd(y,x%y):x;
}
void dfs(int x,vector<int> xx,int xxx){
	vis[x]=true;
	vector<int> yy;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!vis[v]){
			yy.clear();
			for (int j=0;j<xx.size();j++){
				yy.pb(gcd(xx[j],va[v]));
			}
			yy.pb(xxx);
			sort(yy.begin(),yy.end());
			yy.resize(unique(yy.begin(),yy.end())-yy.begin());
			ans[v]=yy.back();
			dfs(v,yy,gcd(xxx,va[v]));
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&va[i]);
	}
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u); 
	}
	vector<int> tmp;
	tmp.pb(0);
	dfs(1,tmp,va[1]);
	ans[1]=va[1];
	for (int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}