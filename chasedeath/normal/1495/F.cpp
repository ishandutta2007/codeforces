#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,INF=1e9+10;

int n,m;
int a[N],b[N],v[N],fa[N][20];
ll s[N][20],t[N];
int S[N],T;
struct Sparse_Table{
	int s[20][N];
	void Build() {
		rep(i,1,n) s[0][i]=v[i];
		rep(i,1,19) {
			int len=1<<(i-1);
			rep(j,1,n-len+1) s[i][j]=min(s[i-1][j],s[i-1][j+len]);
		}
	}
	int Go(int i,int x) {
		drep(j,19,0) if(s[j][i]>x) i+=1<<j;
		return i;
	}
} ST;

set <int> st;
ll Que(int a,int b){
	ll ans=0;
	while(1) {
		drep(i,19,0) if(fa[a][i]<=b) ans+=s[a][i],a=fa[a][i];
		if(a==b) break;
		//assert(p<=b && v[p]<=v[b]);
		ans+=::a[a],a++;
	}
	//drep(i,19,0) if(fa[a][i]<=b) ans+=s[a][i],a=fa[a][i];
	/*if(a!=b) {
		cout<<a<<' '<<b<<' '<<v[a]<<' '<<v[b]<<endl;
		rep(i,0,19) cout<<fa[a][i]<<' ';
		puts("");
		exit(0);
	}*/
	//assert(a==b);
	return ans;
}

int main(){
	n=rd(),m=rd();
	rep(i,1,n) v[i]=rd();
	ST.Build();
	rep(i,1,n) a[i]=rd(),t[i]=t[i-1]+a[i];
	rep(i,1,n) b[i]=rd();
	rep(i,1,n) {
		while(T && v[S[T]]<v[i]) fa[S[T--]][0]=i;
		S[++T]=i;
	}
	rep(i,0,19) fa[n+1][i]=fa[n+2][i]=n+2;
	while(T) fa[S[T--]][0]=n+1;
	drep(i,n,1) {
		s[i][0]=min((ll)b[i],Que(i+1,fa[i][0])+a[i]);
		//cout<<"$Init "<<i<<' '<<fa[i][0]<<' '<<s[i][0]<<endl;
		rep(j,1,19) {
			fa[i][j]=fa[fa[i][j-1]][j-1];
			s[i][j]=s[i][j-1]+s[fa[i][j-1]][j-1];
		}
	}
	//rep(i,1,n) rep(j,i+1,n+1) cout<<"$Que "<<i<<' '<<j<<' '<<Que(i,j)<<endl;
	ll ans=0;
	st.insert(1),st.insert(n+1),ans=Que(1,n+1);
	while(m--) {
		int x=rd();
		if(x!=1) {
			auto it=st.lower_bound(x);
			if(*it!=x) {
				auto p=it; p--;
				ans-=Que(*p,*it);
				ans+=Que(*p,x); ans+=Que(x,*it);
				st.insert(x);
			} else {
				auto l=it; l--;
				auto r=it; r++;
				ans-=Que(*l,x); ans-=Que(x,*r);
				st.erase(it);
				ans+=Que(*l,*r);
			}
		}
		printf("%lld\n",ans);
	}
}