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

const int N=1000005;
int p[N],n,x,y,z,a,b,c;
ll sum[N],K;

ll calc(int t){
	int A=t/c,B=t/a-A,C=t/b-A;
	return sum[A]/100*z
		+(sum[A+B]-sum[A])/100*x
		+(sum[A+B+C]-sum[A+B])/100*y;
}

void rmain(){
	read(n);
	rep(i,1,n)read(p[i]);
	sort(p+1,p+n+1,greater<int>());
	rep(i,1,n)sum[i]=sum[i-1]+p[i];
	read(x),read(a),read(y),read(b),read(K);
	if(x<y)swap(x,y),swap(a,b);
	z=x+y,c=min(n+1ll,(ll)a*b/__gcd(a,b));
	int l=0,r=n+1,mi;
	while(l<r){
		mi=(l+r)>>1;
		if(calc(mi)>=K)r=mi;
		else l=mi+1;
	}
	if(r>n)puts("-1");
	else printf("%d\n",l);
}

int main(){
	int T; read(T);
	while (T--) rmain();
	return 0;
}