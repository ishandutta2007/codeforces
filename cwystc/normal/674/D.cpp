#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const LL INF=1e18;
LL delta,tag[500010],ans,c[500010],b[500010];
int d[500010],A,B,x,tp,n,q,a[500010];
multiset<LL> mn[100010],MN;
multiset<LL,greater<LL> > mx[100010],MX;
void era(int x,LL t){
	LL now=(*mn[x].begin())+tag[x];
	MN.erase(MN.find(now));
	mn[x].erase(mn[x].find(t));
	now=(*mn[x].begin())+tag[x];
	MN.insert(now);
	now=(*mx[x].begin())+tag[x];
	MX.erase(MX.find(now));
	mx[x].erase(mx[x].find(t));
	now=(*mx[x].begin())+tag[x];
	MX.insert(now);
}
void ins(int x,LL t){
	LL now=(*mn[x].begin())+tag[x];
	MN.erase(MN.find(now));
	mn[x].insert(t);
	now=(*mn[x].begin())+tag[x];
	MN.insert(now);
	now=(*mx[x].begin())+tag[x];
	MX.erase(MX.find(now));
	mx[x].insert(t);
	now=(*mx[x].begin())+tag[x];
	MX.insert(now);
}
void addtag(int x,LL t){
	LL now=(*mn[x].begin())+tag[x];
	MN.erase(MN.find(now));
	now+=t;
	MN.insert(now);
	now=(*mx[x].begin())+tag[x];
	MX.erase(MX.find(now));
	now+=t;
	MX.insert(now);
	tag[x]+=t;
}
int main(){
	cin>>n>>q;
	FOR(i,1,n){
		mn[i].insert(INF),mx[i].insert(-INF);
		MN.insert(INF),MX.insert(-INF);
	}
	FOR(i,1,n) scanf("%lld",&b[i]);
	FOR(i,1,n) getint(a[i]);
	FOR(i,1,n) d[i]=1;
	FOR(i,1,n) ++d[i],++d[a[i]];
	FOR(i,1,n) c[i]=b[i]%d[i]+b[i]/d[i];
	FOR(i,1,n) c[i]+=b[a[i]]/d[a[i]],c[a[i]]+=b[i]/d[i];
	FOR(i,1,n) ins(a[i],c[i]);
	while (q--){
		getint(tp);
		if (tp==1){
			getint(x),getint(B);
			A=a[x];
			a[x]=B;
			
			if (A==B) continue;
			
			era(A,c[x]);
			c[x]+=tag[A];
			delta=-b[A]/d[A];
			delta+=b[B]/(d[B]+1);
			c[x]+=delta;
			
			int fa=a[A];
			int gfa=a[fa];
			delta=b[A]%(d[A]-1)-b[A]%d[A]+b[A]/(d[A]-1)-b[A]/d[A]-b[x]/d[x];
			era(fa,c[A]);
			c[A]+=delta;
			ins(fa,c[A]);
			delta=b[A]/(d[A]-1)-b[A]/d[A];
			era(gfa,c[fa]);
			c[fa]+=delta;
			ins(gfa,c[fa]);
			
		//	tag[A]+=delta;
			addtag(A,delta);
			
			fa=a[B];
			gfa=a[fa];
			delta=b[B]%(d[B]+1)-b[B]%d[B]+b[B]/(d[B]+1)-b[B]/d[B]+b[x]/d[x];
			era(fa,c[B]);
			c[B]+=delta;
			ins(fa,c[B]);
			delta=b[B]/(d[B]+1)-b[B]/d[B];
			era(gfa,c[fa]);
			c[fa]+=delta;
			ins(gfa,c[fa]);
		
		//	tag[B]+=delta;
			addtag(B,delta);
			
			c[x]-=tag[B];
			ins(B,c[x]);
			--d[A];
			++d[B];
			
		}
		else if (tp==2){
			getint(x);
			ans=c[x]+tag[a[x]];
			printf("%lld\n",ans);
		}
		else{
			printf("%lld %lld\n",(*MN.begin()),(*MX.begin()));
		}
	}
	return 0;
}