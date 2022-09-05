#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
//const int N = ;
int n,P,Q;ui res,f[133][133],C[133][133];
Vi pr[133];
int main() {
	read(n);read(P);read(Q);umin(P,n-1);
	rep(i,1,P+1){
		int x=i;
		while(x>1){
			rep(j,2,x)if(x%j==0){x/=j,pr[i].pb(j);break;}
		}
	}
	rep(x,0,P){//C[x][i]=C(n-x,i)
		static ui s[133];int len=0;
		rep(i,0,P){
			C[x][i]=1;rep(j,1,len)C[x][i]*=s[j];
			s[++len]=n-x-i;
			rep(j,0,SZ(pr[i+1])-1)rep(k,1,len)if(s[k]%pr[i+1][j]==0){
				s[k]/=pr[i+1][j];break;
			}
		}
	}
	/*rep(i,0,P)f[0][i]=1;
	rep(t,1,Q){
		int p=t&1,q=p^1;//q-->p
		rep(i,0,P){
			f[p][i]=0;
			rep(j,0,P-i)f[p][i]+=C[i][j]*f[q][i+j];
		}
		res^=(ui)f[p][0]*(ui)t;
	}*/
	rep(i,0,P)f[0][i]=1;
	rep(t,1,P){
		int p=t&1,q=p^1;//q-->p
		rep(i,0,P){
			f[t][i]=0;
			rep(j,1,P-i)f[t][i]+=C[i][j]*f[t-1][i+j];
		}
	}
	static ui cc[133];cc[0]=1;
	rep(i,1,Q){
		ui ans=0;
		per(j,P,1)cc[j]+=cc[j-1];
		rep(j,0,P)ans+=f[j][0]*cc[j];
	//	cerr<<ans<<endl;
		res^=(ui)i*ans;
	}
	cout<<res;
	return 0;
}