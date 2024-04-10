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

const int N=1<<19,P=998244353;

vector <int> A[N];

int Que(int u,int v,int w) {
	printf("? %d %d %d\n",u,v,w),fflush(stdout);
	return rd();
}
const int D=80;

int main() {
	int h=rd(),n=(1<<h)-1;
	int u,v;
	do u=rand()%n+1,v=rand()%n+1;
	while(u==v);
	
	if(1ll*n*n<=420) {
		while(1) {
			int u,v;
			do u=rand()%n+1,v=rand()%n+1;
			while(u==v);
			rep(i,1,n) A[i].clear();
			rep(i,1,n) if(i!=u && i!=v) {
				int x=Que(u,v,i);
				A[x].pb(i);
			}
			rep(i,1,n) if((int)A[i].size()==n/2+1) return printf("! %d\n",i),0;
			rep(i,1,n) if((int)A[i].size()==1 && i!=u && i!=v) return printf("! %d\n",i),0;
		}
		return 0;
	}

	rep(t,1,420/D) {
		rep(i,1,n) A[i].clear();
		rep(i,1,D) {
			int w;
			do w=rand()%n+1;
			while(u==w || v==w);
			int x=Que(u,v,w);
			A[x].pb(w);
		}
		int ma=0,ma2=0;
		rep(i,1,n) if(i!=u && i!=v) {
			int t=A[i].size();
			if(t>ma) swap(ma,t);
			if(t>ma2) ma2=t;
		}
		//cout<<"! "<<ma<<' '<<ma2<<endl;
		//return 0;
		if(1.0*ma2/ma>=0.7 || ma<=(D-2)*0.34) break;
		rep(i,1,n) if((int)A[i].size()==ma && i!=v && i!=u) {
			u=i;
			do v=A[i][rand()%A[i].size()];
			while(v==u);
			break;
		}
	}
	rep(i,1,n) A[i].clear();
	rep(i,1,n) if(i!=u && i!=v) {
		int x=Que(u,v,i);
		A[x].pb(i);
	}
	rep(i,1,n) if((int)A[i].size()==n/2+1) return printf("! %d\n",i),0;
	rep(i,1,n) if((int)A[i].size()==1 && i!=u && i!=v) return printf("! %d\n",i),0;
}