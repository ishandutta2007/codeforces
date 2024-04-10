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
typedef long double ld;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=105,M=20005;
ld f[N][M],ans;
int c[N],n,x,s;

int main(){
	read(n),read(x);
	rep(i,1,n){
		read(c[i]);
		c[i]=c[i]*2-x;
	}
	s=0,f[0][0]=1;
	rep(i,1,n){
		per(a,i-1,0) rep(b,0,s)
			if(f[a][b]) f[a+1][b+c[i]]+=f[a][b]*(a+1)/(n-a);
		s+=c[i];
	}
	rep(a,1,n) rep(b,0,s)
		if(f[a][b]) ans+=f[a][b]*min(b,x*n)/a;
	printf("%.10lf\n",double(ans+n*x)/2);
	return 0;
}