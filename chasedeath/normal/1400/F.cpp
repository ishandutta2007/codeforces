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

const int N=1010,INF=1e9+10;

int n,m;
string s;
typedef vector <int> V;
map <V,int>  M;
int a[N];
pair <V,int> stk[N*N];
int top;

int main() {
	cin>>s,m=rd();
	M.emplace(V{},0);
	int ans=0;
	for(char y:s) {
		int x=y-'0';
		for(auto st:M) {
			n=st.first.size();
			int val=st.second+1;
			rep(i,0,n-1) a[i]=st.first[i];
			//puts("STATE!");
			//rep(i,0,n-1) cout<<a[i]<<' ';
			//puts("");
			//cout<<"val ="<<val-1<<endl;
			a[n++]=x;
			V T;
			int s=0,f=1;
			drep(i,n-1,0) {
				s+=a[i];
				if(s==m) { f=0; break; }
				if(m%s==0 || s>m) {
					rep(j,i+1,n-1) T.pb(a[j]);
					break;
				}
				if(i==0) rep(j,i,n-1) T.pb(a[j]);
			}
			if(!f) continue;
			//if(x==8) ;
			//if(val==7) {
				//puts("!");
				//cout<<"Add "<<y<<endl;
				//rep(j,0,T.size()-1) cout<<T[j]<<' ';
				//puts("");
			//}
			cmax(ans,val);
			stk[++top]=mp(T,val);
		}
		while(top) cmax(M[stk[top].first],stk[top].second),top--;
	}
	printf("%d\n",(int)s.size()-ans);
}