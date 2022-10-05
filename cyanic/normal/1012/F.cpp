#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const ll inf=1e15;
const int N=25,M=(1<<22)+5;
struct node{
	int s,len,t,id;
} a[N];
int g[M],h[M],p[N],ty[N],tim[N],cro[N],n,P;
ll f[M];

int main(){
	read(n),read(P);
	REP(i,n){
		read(a[i].s);
		read(a[i].len);
		read(a[i].t);
		a[i].id=i+1;
		p[i]=i;
	}
	sort(a,a+n,[&](node x,node y){
		return x.s<y.s;
	});
	sort(p,p+n,[&](int x,int y){
		return a[x].t<a[y].t;
	});
	memset(f,0x3f,sizeof f);
	f[0]=1;
	REP(s,1<<n){
		if(f[s]>=inf) continue;
		int j=0,l=0,las=f[s];
		//printf("%d  %lld  %d %d\n",s,f[s],g[s],h[s]);
		REP(i,n){
			int k=p[i];
			if(s>>k&1) continue;
			for(int flag=-1;flag;){
				flag=0;
				while(j<n&&(!(s>>j&1)||a[j].s-las<=a[k].t)){
					if(s>>j&1) las=max(las,a[j].s+a[j].len);
					j++,flag|=1;
				}
				while(l+1<n&&a[l+1].s<=las) l++;
				if(a[l].s<=las&&las<a[l].s+a[l].len){
					las=a[l].s+a[l].len;
					flag|=2;
				}
			}
			ll nw=las+a[k].t;
			if(nw<a[k].s&&nw<f[s|(1<<k)]){
				f[s|(1<<k)]=nw;
				g[s|(1<<k)]=k;
				h[s|(1<<k)]=las;
			}
		}
	}
	auto upd=[&](int s,int typ){
		for(;s;s^=1<<g[s]){
			int k=a[g[s]].id;
			ty[k]=typ,tim[k]=h[s];
		}
	};
	int ALL=(1<<n)-1;
	if(P==1){
		if(f[ALL]<inf) upd((1<<n)-1,1);
		else puts("NO"),exit(0);
	}
	else{
		int flag=0;
		REP(s,1<<n) if(!flag&&f[s]<inf&&f[s^ALL]<inf)
			upd(s,1),upd(s^ALL,2),flag=1;
		if(!flag) puts("NO"),exit(0);
	}
	puts("YES");
	rep(i,1,n) printf("%d %d\n",ty[i],tim[i]);
	return 0;
}