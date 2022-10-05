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

const int N=5e5+5,mod=1e9+7;
int c[65],n,ans;
ll x[N];

void rmain(){
	read(n);
	memset(c,0,sizeof c);
	rep(i,1,n){
		read(x[i]);
		REP(j,60){
			if(x[i]>>j&1) c[j]++;
		}
	}
	ans=0;
	rep(i,1,n){
		int A=0,B=0;
		per(j,59,0){
			if(x[i]>>j&1){
				A=(A*2+c[j])%mod;
				B=(B*2+n)%mod;
			}
			else{
				A=A*2%mod;
				B=(B*2+c[j])%mod;
			}
		}
		ans=(ans+(ll)A*B)%mod;
	}
	printf("%d\n",ans);
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();
	return 0;
}