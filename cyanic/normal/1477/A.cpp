#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=2e5+5;
ll x[N],K,g;
int n;

void rmain(){
	read(n),read(K),g=0;
	rep(i,1,n){
		read(x[i]);
		g=__gcd(g,x[i]-x[1]);
	}
	g=abs(g);
	puts((K-x[1])%g==0?"YES":"NO");
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();
	return 0;
}