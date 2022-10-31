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
vector<int> a[Maxn];
vector<pair<int,int> > now;
vector<int> G[Maxn];
int deg[Maxn];
bool vis[Maxn];
vector<int> ans;
int p[Maxn],p2[Maxn];
void _init(int siz){
	for (int i=0;i<siz;i++) p[i]=i,p2[i]=i;
}
int f1(int x){
	return p[x]=(p[x]==x)?x:f1(p[x]);
}
int f2(int x){
	return p2[x]=(p2[x]==x)?x:f2(p2[x]);
}
int cnt;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	cnt=m;
	for (int i=1;i<=n;i++){
		a[i].resize(m+3);
		now.clear();
		for (int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if (a[i][j]!=-1)now.push_back(mp(a[i][j],j));
		}
		if (now.empty()) continue;
		sort(now.begin(),now.end());
		_init(now.size()+2);
		for (int j=0;j<now.size()-1;j++){
			if (now[j].first==now[j+1].first) p[j]=j+1,p2[j+1]=j;
		}
		for (int j=0;;){
			int s=f1(j);
			if (s==now.size()-1) break;
			int newnode=++cnt;
			for (int k=j;k<=s;k++){
				G[now[k].second].push_back(newnode);
			}
			j=s+1;
			s++;
			int ss=f1(s);
			for (int k=s;k<=ss;k++){
				G[newnode].push_back(now[k].second);
			}
		}
	}
	for (int i=1;i<=cnt;i++){
	//	sort(G[i].begin(),G[i].end());
	//	G[i].resize(unique(G[i].begin(),G[i].end())-G[i].begin());
		for (int j=0;j<G[i].size();j++){
			deg[G[i][j]]++;
			//cout<<G[i][j]<<' ';
		}
		//cout<<endl;
	}
	memset(vis,false,sizeof(vis));
	vector<int> vv;
	for (int i=1;i<=cnt;i++){
		if (!deg[i]){
			vv.pb(i);
		}
	}
	//random_shuffle(vv.begin(),vv.end());
//	reverse(vv.begin(),vv.end());
	while (!vv.empty()){
		int x=vv.back();
		vv.pop_back();
		vis[x]=true;
		if (x<=m) ans.push_back(x);
		for (int i=0;i<G[x].size();i++){
			deg[G[x][i]]--;
			if (!deg[G[x][i]]) vv.pb(G[x][i]);
		}
	}
	for (int i=1;i<=m;i++){
		if (!vis[i]){
			printf("-1\n");
			return 0;
		}
	}
	vector<int> tmp;
	for (int i=1;i<=n;i++){
		tmp.resize(m+1);
		for (int j=1;j<=m;j++){
			tmp[j]=a[i][ans[j-1]];
		}
	//	for (int j=1;j<=m;j++) cout<<tmp[j]<<' ';
	//	cout<<endl;
		for (int j=1;j<=m;j++){
			if (tmp[j]==-1) tmp[j]=tmp[j-1];
		}
		for (int j=1;j<=m-1;j++){
			if (tmp[j]>tmp[j+1]){
				return tmp[j+1];
			}
		}
	}
	for (int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	return 0;
}