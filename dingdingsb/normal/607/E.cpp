#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
#define lowbit(x) ((x)&-(x))
const int N=1e5+10;
typedef long long ll;
typedef long double db;
const db pi=acos(-1),eps=1e-10;
#define sq(x) (x)*(x)
int n,m,top;
db p,q,a[N],b[N];
int id[N];pair<db,int>s[N];
db get(db x,db y){return atan2(x,y);}
void work(db r){
	top=0;memset(id,0,sizeof id);
	for(int i=1;i<=n;i++){
		db delta=4*sq(a[i])*sq(b[i])-4*(sq(a[i])+1)*(sq(b[i])-sq(r));
		if(delta<eps)continue;
		delta=sqrt(delta);
		double x1=(-2*a[i]*b[i]+delta)/(2*sq(a[i])+2);
		double x2=(-2*a[i]*b[i]-delta)/(2*sq(a[i])+2);
		double y1=a[i]*x1+b[i],y2=a[i]*x2+b[i];
		s[++top]=mp(get(x1,y1),i);
		s[++top]=mp(get(x2,y2),i);
	}
	sort(s+1,s+1+top);
	for(int i=top;i;i--)if(!id[s[i].se])id[s[i].se]=i;
}
struct BIT{
	int tree[N];
	void init(){memset(tree,0,sizeof tree);}
	void upd(int x){for(;x<=top;x+=lowbit(x))tree[x]++;}
	int qry(int x){int res=0;for(;x;x-=lowbit(x))res+=tree[x];return res;}
}T;
ll cnt(db r){
	work(r);T.init();ll ans=0;
	for(int i=1;i<=top;i++)if(id[s[i].se]!=i){
		ans+=T.qry(id[s[i].se])-T.qry(i);
		T.upd(id[s[i].se]);
	}
	return ans;
}
db dis(int p,int q){
	db x=(b[q]-b[p])/(a[p]-a[q]);
	db y=a[p]*x+b[p];
	return sqrt(sq(x)+sq(y));
}
db calc(db r){
	work(r);
	set<pair<int,int>>now;int cnt=0;db ans=0;
	for(int i=1;i<=top;i++)if(id[s[i].se]!=i){
		auto it=now.upper_bound(mp(i+1,0));
		while(it!=now.end()&&(it->fi)<id[s[i].se])
			ans+=dis(s[i].se,it->se),cnt++,it++;
		now.insert(mp(id[s[i].se],s[i].se));
	}
	return ans+(m-cnt)*r;
}
signed main(){
	scanf("%d%Lf%Lf%d",&n,&p,&q,&m);p/=1000,q/=1000;
	for(int i=1;i<=n;i++)scanf("%Lf%Lf",&a[i],&b[i]),a[i]/=1000,b[i]/=1000,b[i]+=a[i]*p-q;
	db l=0,r=1e10;
	for(int SJYAK=1;SJYAK<=100;SJYAK++){
		db mid=(l+r)/2;
		if(cnt(mid)>=m)r=mid;
		else l=mid;
	}
	printf("%.10Lf",max((db)0,calc(r)));
}