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
const int Maxn=100005;
int p[Maxn];
int siz[Maxn];
void _init(){
	for (int i=0;i<Maxn;i++) p[i]=i,siz[i]=1; 
}
int findset(int x){
	return p[x]=(p[x]==x)?x:findset(p[x]);
}
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	p[y]=x;
	siz[x]+=siz[y];
}
map<int,vector<pair<int,pair<int,int> > > > e;
bool vis[Maxn];
vector<pair<int,int> > G[Maxn];
int szz[Maxn];
LL res[Maxn];
int col[Maxn];
int tots[Maxn];
bool sss[Maxn];
int cnt;
void dfs(int x,int cc){
	vis[x]=true;
	col[x]=cc;
	if (!sss[findset(x)])tots[cc]+=siz[findset(x)];
	sss[findset(x)]=true;
//	szz[x]=0;
	
	for (int i=0;i<G[x].size();i++){
		if (!vis[G[x][i].first]){
			dfs(G[x][i].first,cc);
			szz[x]+=szz[G[x][i].first];
			if (findset(x)==findset(G[x][i].first)) szz[x]-=siz[findset(x)];
		}
	}
	szz[x]+=siz[findset(x)];
//	cout<<'d'<<x<<' '<<szz[x]<<endl;
	//assert(szz[x]<=tots[cc]);
}
int main(){
	_init();
	int n;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		e[c].pb(mp(i,mp(u,v)));
	}
	for (auto cv:e){
		cnt=0;
		vector<pair<int,pair<int,int> > > v=cv.second;
		//cout<<cv.first<<' '<<v.size()<<endl; 
		vector<int> vv;
		for (int i=0;i<v.size();i++){
			vv.pb(v[i].second.first);
			vv.pb(v[i].second.second);
		} 
		sort(vv.begin(),vv.end());
		vv.resize(unique(vv.begin(),vv.end())-vv.begin());
		int cccc=0;
		for (int i=0;i<vv.size();i++){
			cccc+=siz[findset(vv[i])];
			sss[findset(vv[i])]=false;
			G[vv[i]].clear(); 
			szz[vv[i]]=0;
			vis[vv[i]]=false;
			col[vv[i]]=0;
		}
		vector<pair<int,int> > vvvv;
		for (int i=0;i<vv.size();i++){
			vvvv.pb(mp(findset(vv[i]),vv[i]));
		}
		sort(vvvv.begin(),vvvv.end());
		for (int i=0;i<vvvv.size()-1;i++){
			if (vvvv[i].first==vvvv[i+1].first){
			//	cout<<"add"<<' '<<vvvv[i].second<<' '<<vvvv[i+1].second<<endl;
				G[vvvv[i].second].pb(mp(vvvv[i+1].second,-1));
				G[vvvv[i+1].second].pb(mp(vvvv[i].second,-1));
			}
		}
	//	cout<<"fuck"<<cccc<<endl;
		for (int i=0;i<v.size();i++){
			G[v[i].second.first].pb(mp(v[i].second.second,v[i].first));
			G[v[i].second.second].pb(mp(v[i].second.first,v[i].first));
		}
		for (int i=0;i<vv.size();i++){
			if (!vis[vv[i]]){
				tots[cnt+1]=0;
				dfs(vv[i],++cnt);
			}
		}
		for (int i=0;i<v.size();i++){
			if (szz[v[i].second.first]>szz[v[i].second.second]) swap(v[i].second.first,v[i].second.second);
			int ss=szz[v[i].second.first],tt=(tots[col[v[i].second.first]]-szz[v[i].second.first]);
		//	cout<<'f'<<" "<<ss<<" "<<tt<<' '<<szz[v[i].second.first]<<' '<<tots[col[v[i].second.first]]<<endl;
			res[v[i].first]=1ll*ss*tt;
		}
		for (int i=0;i<v.size();i++){
		//	cout<<'u'<<' '<<siz[findset(v[i].second.first)]<<' '<<siz[findset(v[i].second.second)]<<endl;
		//	cout<<'u'<<' '<<v[i].second.first<<' '<<v[i].second.second<<endl;
			Union(v[i].second.first,v[i].second.second);
		}
	}
	vector<int> mxx;
	LL mx=0;
	for (int i=0;i<n-1;i++){
		if (res[i]>mx){
			mx=res[i];
			mxx.clear();
			mxx.pb(i);
		}
		else if (res[i]==mx){
			mxx.pb(i);
		}
	}
	printf("%I64d %d\n",2*mx,mxx.size());
	for (int i=0;i<mxx.size();i++){
		printf("%d ",mxx[i]+1);
	}
	return 0;
} 
/*
9
5 9 2
7 3 3
8 5 3
6 7 3
9 7 1
3 2 1
4 7 4
1 9 1
*/