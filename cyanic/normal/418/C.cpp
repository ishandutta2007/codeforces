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

void cmin(ll &x,const ll y){
	if(y<x) x=y;
}

const int N=105,M=10005;
int a[N],b[N],n,m;
bitset<M> f[N];

void search(int n,int a[]){
	f[0].set(0);
	rep(i,1,n) rep(j,1,100){
		f[i]|=f[i-1]<<(j*j);
	}
	int aim=1;
	while(!f[n][aim*aim]) aim++;
	aim*=aim;
	per(i,n,1){
		int k=0;
		rep(j,1,100){
			if(aim>=j*j&&f[i-1][aim-j*j]){
				k=j; break;
			}
		}
		a[i]=k;
		aim-=k*k;
	}
}

int main(){
	read(n),read(m);
	search(n,a);
	search(m,b);
	rep(i,1,n){
		rep(j,1,m){
			printf("%d ",a[i]*b[j]);
		}
		puts("");
	}

	return 0;
}