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

ll a,b,c,d;

void rmain(){
	read(a),read(b);
	read(c),read(d);
	swap(c,d);
	if(a>b*d){
		puts("-1");
		return;
	}
	ll t=a/b/c;
	ll ans=a*(t+1);
	ans-=t*(t+1)/2*c*b;
	printf("%lld\n",ans);
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}