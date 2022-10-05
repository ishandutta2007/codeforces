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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

int f[23333];

void test(){
	int n; read(n);
	rep(i,1,n){
		int a=1;
		while(f[a]) a++;
		int b=a+1;
		for(;;b++){
			while(f[b]) b++;
			if((a^b)>b&&!f[a^b]){
				printf("%d %d %d\n",a,b,a^b);
				f[a]=f[b]=f[a^b]=1;
				break;
			}
		}
	}
}

const int c[3][4]={
	{0,1,2,3},
	{0,2,3,1},
	{0,3,1,2}
};

vector<ll> solve(int k,ll n){
	if(!k) return {1,2,3};
	vector<ll> ret=solve(k-1,n/4);
	REP(i,3) ret[i]=ret[i]*4+c[i][n%4];
	return ret;
}

void rmain(){
	ll n,r,c;
	read(n),n--,r=n/3,c=n%3;
	int k=0;
	while(r>=(1ll<<(2*k))){
		r-=1ll<<(2*k),k++;
	}
	printf("%lld\n",solve(k,r)[c]);
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}