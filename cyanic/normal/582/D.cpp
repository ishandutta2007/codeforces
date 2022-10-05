#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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

const int N=3333,mod=1e9+7;

void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
void sub(int &x,int y){
	x=(x-y<0?x-y+mod:x-y);
}
int mul(int x,int y){
	return static_cast<ll>(x)*y%mod;
}

int p;

int F(int x,int a,int b){
	return !a?x+1-b:p-(x+1-b);
}

int G(int x,int a,int b){	// G(x) = sum F(k)   k < x	
	int res=((ll)x*(x+1)/2-b*x)%mod;
	return !a?res:((ll)p*x-res)%mod;
}

int f[N][N][2][2],num[N],x[N];
int n,m,lim,ans;
char s[N];

int main(){
	read(p),read(lim);
	scanf("%s",s+1),m=strlen(s+1);
	rep(i,1,m)num[i]=s[m+1-i]-'0';
	for(int i=1;m;i++){
		ll r=0;
		per(j,m,1){
			r=r*10+num[j];
			num[j]=r/p,r%=p;
		}
		x[++n]=r;
		while(m&&!num[m])m--;
	}
	reverse(x+1,x+n+1);
	if(lim>n)return puts("0"),0;
	f[0][0][1][0]=1;
	rep(i,1,n)rep(j,0,lim)REP(e,2)REP(a,2){
		int val=f[i-1][j][e][a];
		if(!val)continue;
		REP(b,2){
			int c=(j==lim?lim:j+b);
			if(!e)	add(f[i][c][e][b],mul(G(p,a,b),val));
			else	add(f[i][c][e][b],mul(F(x[i],a,b),val)),
					add(f[i][c][0][b],mul(G(x[i],a,b),val));
		}
	}
	add(ans,f[n][lim][0][0]);
	add(ans,f[n][lim][1][0]);
	cout<<ans<<endl;
	return 0;
}