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
#define pb push_back
#define mp make_pair
using namespace std;
//orz mqy
const int Maxn=100005;
const int Maxk=450;
vector<pair<int,int> > co[Maxn];
int p[Maxn];
vector<int> u;
vector<int> bl[Maxn];
set<int> bb[Maxn];
int id[Maxn];
int to[Maxn];
map<pair<int,int>,int> ans;
vector<int> big;
vector<int> cmp[Maxn*5];
int table[Maxk][Maxn];
int findset(int x){
	return p[x]=(p[x]==x)?x:findset(p[x]);
}
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	if (x==y) return;
	p[x]=y;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		co[c].pb(mp(a,b));
	}
	for (int i=0;i<Maxn;i++){
		p[i]=i;
	}
	int cnt=0;
	for (int i=1;i<=m;i++){
		u.clear();
		for (int j=0;j<co[i].size();j++){
			u.push_back(co[i][j].first);
			u.push_back(co[i][j].second);
			Union(co[i][j].first,co[i][j].second);
		}
		sort(u.begin(),u.end());
		u.resize(unique(u.begin(),u.end())-u.begin());
		int tot=0;
		for (int j=0;j<u.size();j++){
			if (!to[findset(u[j])]) to[findset(u[j])]=(++tot)+cnt;
			cmp[to[findset(u[j])]].push_back(u[j]);
		}
		for (int j=0;j<u.size();j++){
			bl[u[j]].push_back(to[p[u[j]]]);
		}
		cnt+=tot;
		for (int j=0;j<u.size();j++){
			to[p[u[j]]]=0;
			p[u[j]]=u[j];
		}
	}
	/*
	for (int i=1;i<=cnt;i++){
		for (int j=0;j<cmp[i].size();j++){
			printf("%d ",cmp[i][j]);
		}
		printf("\n");
	}*/
	/*
	for (int i=1;i<=n;i++){
		for (int j=0;j<bl[i].size();j++){
			bb[i].insert(bl[i][j]);
		}
	}
	*/
	memset(id,-1,sizeof(id));
	for (int i=1;i<=n;i++){
		if (bl[i].size()>450) big.push_back(i),id[i]=big.size()-1;
	}
	for (int i=0;i<big.size();i++){
		int u=big[i];
		for (int j=0;j<bl[u].size();j++){
			int cpn=bl[u][j];
			for (int k=0;k<cmp[cpn].size();k++){
				table[i][cmp[cpn][k]]++;
			}
		}
	}
	int q;
	scanf("%d",&q);
	while (q--){
		
		int a,b;
		scanf("%d %d",&a,&b);
		/*
		if (bb[a].size()>bb[b].size()) swap(a,b);
		if (ans.count(mp(a,b))){
			printf("%d\n",ans[mp(a,b)]);
		} 
		else{
			int res=0;
			for (set<int>::iterator it=bb[a].begin();it!=bb[a].end();it++){
				if (bb[b].count(*it)){
					res++;
				}
			}
			printf("%d\n",ans[mp(a,b)]=res);
		}*/
		if (bl[a].size()>450){
			printf("%d\n",table[id[a]][b]);
		}
		else if (bl[b].size()>450){
			printf("%d\n",table[id[b]][a]);
		}
		else {
			int p1=0,p2=0;
			int ans=0;
			for (;;){
				if (p1==bl[a].size() || p2==bl[b].size()){
					break;
				}
				if (bl[a][p1]==bl[b][p2]){
					ans++;
					p1++,p2++;
				}
				else if (bl[a][p1]>bl[b][p2]){
					p2++;
				}
				else{
					p1++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}