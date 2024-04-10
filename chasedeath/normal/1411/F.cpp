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

const int N=1e6+10,P=1e9+7;

int n,m;
int Pow[N];
int A[N],L[N],C,R[N],D;
int vis[N];

int Calc(int c1,int c2){
	int t=min(c1,c2),ans=t;
	c1-=t,c2-=t;
	if(c1) ans+=c1/3*2;
	if(c2) ans+=c2;
	return ans;
}

int Calc(int c1,int c2,int c4){ return c4+Calc(c1+c4,c2); }

int main(){
	rep(i,*Pow=1,N-1) Pow[i]=1ll*Pow[i-1]*3%P;
	rep(_,1,rd()) {
		n=rd();
		rep(i,1,n) A[i]=rd(),vis[i]=0;
		C=0;
		rep(i,1,n) if(!vis[i]) {
			int c=0;
			for(int j=i;!vis[j];j=A[j]) c++,vis[j]=1;
			L[++C]=c;
		}
		//puts("#");
		//rep(i,1,C) cout<<L[i]<<' ';
		//puts("");
		if(n%3==0) {
			printf("%d ",Pow[n/3]);
			int ans=0;
			rep(i,1,C) {
				while(L[i]>3) L[i]-=3,ans++;
				if(L[i]==3) L[i]=0;
			}
			int c1=0,c2=0;
			rep(i,1,C) if(L[i]==1) c1++;
			else if(L[i]==2) c2++;
			ans+=Calc(c1,c2);
			printf("%d\n",ans);
			continue;
		}

		if(n%3==2) {
			printf("%d ",Pow[n/3]*2%P);
			int cnt=n/3,ans=0;
			rep(i,1,C) {
				while(cnt && L[i]>3) L[i]-=3,cnt--,ans++;
				if(L[i]==3 && cnt) L[i]=0,cnt--;
			}
			int c1=0,c2=0;
			rep(i,1,C) if(L[i]==1) c1++;
			else if(L[i]==2) c2++;
			if(c2) c2--;
			else c1-=2,ans++;
			ans+=Calc(c1,c2);
			printf("%d\n",ans);
			continue;
		}
		printf("%lld ",Pow[(n-4)/3]*4ll%P);
		int cnt=(n-4)/3,c3=0,ans=0;
		rep(i,1,C) {
			while(cnt && L[i]>4) L[i]-=3,cnt--,ans++;
			if(L[i]==3 && cnt) L[i]=0,cnt--;
		}
		int c1=0,c2=0,c4=0;
		rep(i,1,C) if(L[i]==1) c1++;
		else if(L[i]==2) c2++;
		else if(L[i]==3) c3++;
		else if(L[i]==4) c4++;
		//cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<endl;
		if(c3) ans++;
		else {
			int w=1e9;
			//cout<<"$"<<c1<<' '<<c2<<' '<<c4<<endl;
			if(c4) cmin(w,Calc(c1,c2,c4-1));
			if(c1>=4) cmin(w,Calc(c1-4,c2,c4)+2);
			if(c2>=2) cmin(w,Calc(c1,c2-2,c4));
			if(c1>=2 && c2)  cmin(w,Calc(c1-2,c2-1,c4)+1);
			ans+=w;
		}
		printf("%d\n",ans);
	}
}