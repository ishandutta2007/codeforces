#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 2020;
bitset<N>a[N];
bool b[N][2][2];int n,k,cnt;
void ope(int *a, char c){
	if(c=='R')a[0]^=1;
	else if(c=='Y')a[1]^=1;
	else if(c=='B')a[0]^=1,a[1]^=1;
}
void gauss(int n, int m){//a[1..n][0..m]
	int gs=0;
	bool x[N]={0};int pos[N]={0};
	/*rep(i,1,n){
		rep(j,0,m)cerr<<a[i][j];cerr<<endl;
	}
	cerr<<endl;*/
	rep(i,1,m){
		if(!a[gs+1][i])rep(j,gs+1,n)if(a[j][i]){
			swap(a[gs+1],a[j]);break;
		}
		if(!a[gs+1][i]){pos[i]=0;continue;}
		gs++;
		rep(j,1,n)if(j!=gs&&a[j][i])a[j]^=a[gs];
		pos[i]=gs;
	}
	rep(j,1,m)if(pos[j])x[j]=a[pos[j]][0];
	/*rep(i,1,n){
		rep(j,0,m)cerr<<a[i][j];cerr<<endl;
	}
	cerr<<endl;*/
	rep(i,1,n)if(a[i].count()==1&&a[i][0]){puts("NO");exit(0);}
	puts("YES");
	rep(i,1,m/2){
		char c='.';
		if(x[2*i-1]&&x[2*i])c='B';
		else if(x[2*i-1])c='R';
		else if(x[2*i])c='Y';
		putchar(c);
	}
}
int main() {
	read(n);read(k);
	rep(i,1,n)b[i][0][0]=b[i][1][1]=1;
	while(k--){
		string t;cin>>t;
		if(t[0]=='m'){
			int l,x;read(l);
			while(l--){
				read(x);
				rep(i,0,1)rep(j,0,1)a[cnt+1+i][2*x-1+j]=b[x][i][j];
			//	a[cnt+1][2*x-1]=a[cnt+1][2*x-1]^1;a[cnt+1][0]=a[cnt+1][0]^f[x];
			//	a[cnt+2][2*x]=a[cnt+2][2*x]^1;a[cnt+2][0]=a[cnt+2][0]^g[x];
			}
			cin>>t;
			if(t[0]=='R')a[cnt+1][0]=a[cnt+1][0]^1;
			else if(t[0]=='Y')a[cnt+2][0]=a[cnt+2][0]^1;
			else if(t[0]=='B')a[cnt+1].flip(0),a[cnt+2].flip(0);
			cnt+=2;
		}
		else{
		//	int q[2]={0};//ope(q,t[0]);ope(q,t[1]);
			bool c[2][2]={0};
			if(t=="RY")c[0][1]=c[1][0]=1;
			else if(t=="RB")c[0][0]=c[1][0]=c[1][1]=1;
			else if(t=="YB")c[0][0]=c[0][1]=c[1][1]=1;
			else assert(0);
			int l,x;read(l);
			while(l--){
				read(x);//f[x]^=q[0];g[x]^=q[1];
				bool d[2][2]={0};
				rep(i,0,1)rep(j,0,1)rep(k,0,1)
					d[i][k]^=c[i][j]&b[x][j][k];
				rep(i,0,1)rep(j,0,1)b[x][i][j]=d[i][j];
			}
		}
	}
	gauss(cnt,2*n);
	return 0;
}