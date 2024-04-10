#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

int h[100005],l[100005],r[100005];
vector < vector <int> > g;

struct item {
	int l,h,ind,tp;
};

bool operator < (const item & a,const item & b) {
	return a.l<b.l||a.l==b.l&&a.tp<b.tp;
}

bool cmp (const item & a,const item & b) {
	return a.h<b.h||a.h==b.h&&a.l<b.l;
}

vector <item> v;
vector <int> y;

int t[400005];

int get(int a) {
	return lower_bound(y.begin(),y.end(),a)-y.begin();
}

void build (int v, int tl, int tr) {
	if (tl == tr)
		t[v] = 1000000001;
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		t[v] = min(t[v*2] , t[v*2+1]);
	}
}

int find(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 1000000001;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return min(find (v*2, tl, tm, l, min(r,tm))
		, find (v*2+1, tm+1, tr, max(l,tm+1), r));
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		while(tl<tr) {
			int m=(tl+tr)>>1;
			if (pos<=m) v<<=1,tr=m;
			else v=v<<1|1,tl=m+1;
		}
		t[v]=new_val; v>>=1;
		while(v) {
			t[v]=min(t[v<<1],t[v<<1|1]);
			v>>=1;
		}
	}
}

set < pair <int,int> > f;
vector < vector <int> > hh;
int pos[100005],n,ans[100005];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int T;
	scanf("%d%d",&n,&T);
	g.resize(n+2);
	h[0]=T; h[n+1]=0;
	l[0]=l[n+1]=-1000000000;
	r[0]=r[n+1]=1000000000;
	v.resize(2*n+2);
	item e1={l[0],h[0],0,1};
	item e2={l[n+1],h[n+1],n+1,1};
	v[0]=e1; v[1]=e2;
	y.reserve(n+2);
	y.push_back(0);
	y.push_back(T);
	for(int i=1;i<=n;++i) {
		scanf("%d%d%d",&h[i],&l[i],&r[i]);
		item e={l[i],h[i],i,1};
		v[2*i]=e;
		item ee={r[i],h[i],i,-1};
		v[2*i+1]=ee;
		y.push_back(h[i]);
	}
	sort(v.begin(),v.end());
	sort(y.begin(),y.end());
	y.resize(unique(y.begin(),y.end())-y.begin());
	hh.resize(y.size());
	for(int i=0;i<=n+1;++i) {
		hh[h[i]=get(h[i])].push_back(l[i]);
	}
	for(int i=0;i<y.size();++i) {
		hh[i].push_back(1000000001);
		sort(hh[i].begin(),hh[i].end());
	}
	build(1,0,y.size()-1);
	for(int i=0;i<y.size();++i) {
		update(1,0,y.size()-1,i,hh[i][0]);
	}
	set < pair <int,int> >::iterator it,it1,it2;
	int cnt=0;
	for(int i=0;i<v.size();) {
		int x=v[i].l;
		while(i<v.size()&&v[i].l==x) {
			if (v[i].tp==-1) {
				f.erase(f.find(make_pair(v[i].h,v[i].ind)));
			} else {
				int ind=v[i].ind,lev=get(v[i].h);//,pos=upper_bound(hh[lev].begin(),hh[lev].end(),v[i].l)-hh[lev].begin();
				update(1,0,y.size()-1,lev,hh[lev][++pos[lev]]);
				it1=it2=it=f.insert(make_pair(v[i].h,v[i].ind)).first;
				if (it!=f.begin()) {
					it1--;
					int L=it1->second,R=it->second;
					int val=find(1,0,y.size()-1,h[L],h[R]);
					if (val>=min(r[L],r[R])) {
						g[R].push_back(L);
						++cnt;
//						cout << R << "	" << L << endl;
					}
				}
				it2++;
				if (it2!=f.end()) {
					int L=it2->second,R=it->second;
					int val=find(1,0,y.size()-1,h[R],h[L]);
					if (val>=min(r[L],r[R])) {
						g[L].push_back(R);
						++cnt;
//						cout << L << "	" << R << endl;
					}
				}
			}
			++i;
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();++i) {
		int u=v[i].ind,cur=0;
		if (u==n+1) cur=2000000000;
		for(int j=0;j<g[u].size();++j) {
			cur=max(cur,min(ans[g[u][j]],min(r[u],r[g[u][j]])-max(l[u],l[g[u][j]])));
		}
		ans[u]=cur;
	}
	printf("%d\n",ans[0]);
	return 0;
}