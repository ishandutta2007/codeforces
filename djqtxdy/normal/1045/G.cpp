/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int maxn=200005;
int n,k,sz;
int val[maxn]; 
class Robot{
public:
	int x,r,q;
	bool operator < (const Robot &o)const{
		return x<o.x;
	}
}a[maxn];
vector<int>pos[maxn],idx[maxn],xs,qs;
vector<pair<pii,int> >qry[maxn];
vector<pii>e[maxn];
vector<int>all;
ll ans;

namespace BIT{
	int t[maxn];
	void init(int tot){
		REP(i,tot)t[i]=0;
	}
	void add(int v,int tot){
		for(v++;v<=tot;v+=(v&-v))t[v]++;
	}
	int sum(int v){
		int res=0;
		for(v++;v;v-=(v&-v))res+=t[v];
		return res; 
	}
}

int main(){
#ifdef FILE
	freopen("G.in","r",stdin);
//	freopen("FILE.out","w",stdout);
#endif
	scanf("%d%d",&n,&k);
	rep(i,n){
		scanf("%d%d%d",&a[i].x,&a[i].r,&a[i].q);
		xs.pb(a[i].x);
		qs.pb(a[i].q);
	}
	sort(a,a+n);
	sort(xs.begin(),xs.end());
	sort(qs.begin(),qs.end());
	qs.resize(unique(qs.begin(),qs.end())-qs.begin());
	rep(i,n){
		int tmp=lower_bound(qs.begin(),qs.end(),a[i].q)-qs.begin();
		pos[tmp].pb(i),idx[tmp].pb(a[i].x);
	}
	rep(i,n){
		int l=lower_bound(xs.begin(),xs.end(),a[i].x-a[i].r)-xs.begin();
		int r=upper_bound(xs.begin(),xs.end(),a[i].x+a[i].r)-xs.begin()-1;
		int id=lower_bound(qs.begin(),qs.end(),a[i].q)-qs.begin();
		int old=id;
		int cr=upper_bound(pos[id].begin(),pos[id].end(),r)-pos[id].begin()-1;
		int cl=lower_bound(pos[id].begin(),pos[id].end(),l)-pos[id].begin();
		qry[id].pb(mp(mp(cl,cr),i));
		while(id-1>=0&&qs[old]-qs[id-1]<=k){
			id--;
			int cr=upper_bound(pos[id].begin(),pos[id].end(),r)-pos[id].begin()-1;
			int cl=lower_bound(pos[id].begin(),pos[id].end(),l)-pos[id].begin();
			qry[id].pb(mp(mp(cl,cr),i));
		}
		id=old;
		while(id+1<qs.size()&&qs[id+1]-qs[old]<=k){
			id++;
			int cr=upper_bound(pos[id].begin(),pos[id].end(),r)-pos[id].begin()-1;
			int cl=lower_bound(pos[id].begin(),pos[id].end(),l)-pos[id].begin();
			qry[id].pb(mp(mp(cl,cr),i));
		}
	}
//	cout<<clock()<<endl;
	rep(id,qs.size()){
		all.clear();
		rep(i,pos[id].size())all.pb(a[pos[id][i]].x+a[pos[id][i]].r);
		rep(i,qry[id].size())all.pb(a[qry[id][i].snd].x);
		sort(all.begin(),all.end());
		all.resize(unique(all.begin(),all.end())-all.begin());
		rep(i,qry[id].size()){
			int tmp=upper_bound(idx[id].begin(),idx[id].end(),a[qry[id][i].snd].x)-idx[id].begin()-1;
			val[i]=tmp;
			if(qry[id][i].fst.fst-1>=0)
			e[qry[id][i].fst.fst-1].pb(mp(a[qry[id][i].snd].x,-1));
			if(tmp>=0)e[tmp].pb(mp(a[qry[id][i].snd].x,1));
		}
		BIT::init(all.size());
		rep(i,pos[id].size()){
			int tmp=pos[id][i];
			BIT::add(lower_bound(all.begin(),all.end(),a[tmp].x+a[tmp].r)-all.begin(),all.size());
			rep(j,e[i].size()){
				int tmp=lower_bound(all.begin(),all.end(),e[i][j].fst)-all.begin();
				ans+=(BIT::sum(all.size()-1)-BIT::sum(tmp-1))*e[i][j].snd; 
			}
			e[i].clear();
		}
		all.clear();
		rep(i,pos[id].size())all.pb(a[pos[id][i]].x-a[pos[id][i]].r);
		rep(i,qry[id].size())all.pb(a[qry[id][i].snd].x);
		sort(all.begin(),all.end());
		all.resize(unique(all.begin(),all.end())-all.begin());
		rep(i,qry[id].size()){
			int tmp=val[i]+1;
			if(qry[id][i].fst.snd+1<pos[id].size())
			e[qry[id][i].fst.snd+1].pb(mp(a[qry[id][i].snd].x,-1));
			if(tmp<pos[id].size())e[tmp].pb(mp(a[qry[id][i].snd].x,1));
		}
		BIT::init(all.size());
		for(int i=pos[id].size()-1;i>=0;i--){
			int tmp=pos[id][i];
			BIT::add(lower_bound(all.begin(),all.end(),a[tmp].x-a[tmp].r)-all.begin(),all.size());
			rep(j,e[i].size()){
				int tmp=lower_bound(all.begin(),all.end(),e[i][j].fst)-all.begin();
				ans+=(BIT::sum(tmp))*e[i][j].snd; 
			}
			e[i].clear();
		}
	}
	ans-=n;
	printf("%lld\n",ans/2);
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/