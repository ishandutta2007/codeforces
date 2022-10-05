#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
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

const int N=2000005;
ll a[N],K;
int n;

void rmain(){
	read(n),read(K);
	rep(i,1,n){
		read(a[i]);
	}
	K=(K-1)%2+1;
	for(;K;K--){
		ll d=-1e18;
		rep(i,1,n){
			d=max(d,a[i]);
		}
		rep(i,1,n){
			a[i]=d-a[i];
		}
	}
	rep(i,1,n){
		printf("%lld ",a[i]);
	}
	puts("");
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();

	return 0;
}