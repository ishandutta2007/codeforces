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
const int Maxn=505;
vector<int> G[Maxn];
int dist[Maxn][Maxn];
pair<int,int> pre[Maxn][Maxn];
int d[Maxn][Maxn];
bool vis[Maxn][Maxn];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
		d[u][v]=d[v][u]=1; 
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for (int i=0;i<=n;i++) for(int j=0;j<=n;j++) dist[i][j]=-1; 
	queue<pair<int,int> > Q;
	Q.push(mp(1,n));
	dist[1][n]=0;
	while (!Q.empty()){
		pair<int,int> x=Q.front();
		Q.pop();
		if (x.first==n && x.second==1) break;
		int u=x.first,v=x.second;
		for (int i=0;i<G[u].size();i++){
			int uu=G[u][i];
			if (vis[uu][v]) continue;
			vis[uu][v]=true;
			for (int j=0;j<G[v].size();j++){
				int vv=G[v][j];
				if (dist[uu][vv]!=-1 || uu==vv) continue;
				Q.push(mp(uu,vv));
				dist[uu][vv]=dist[u][v]+1;
				pre[uu][vv]=mp(u,v);
			}
		}
	}
	//cout<<pre[1][n]<<endl;
	printf("%d\n",dist[n][1]);//return 0;
	if (dist[n][1]==-1){
		return 0;
	}
	vector<int> ans1,ans2;
	int now1=n,now2=1;
	while (now1!=0){
		ans1.push_back(now1);
		ans2.push_back(now2);
		pii tmp=pre[now1][now2];
		now1=tmp.first;
		now2=tmp.second;
	}
	reverse(ans1.begin(),ans1.end());
	reverse(ans2.begin(),ans2.end());
	for (int i=0;i<ans1.size();i++){
		printf("%d ",ans1[i]);
	}
	printf("\n");
	for (int i=0;i<ans2.size();i++){
		printf("%d ",ans2[i]);
	}
	printf("\n");
	return 0;
}