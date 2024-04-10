#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se seoncd
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

const int N=5005;
int a[N],n,m,K;

void rmain(){
	read(n),read(m),read(K);
	rep(i,1,n) read(a[i]);
	K=min(K,m-1);
	int ans=0;
	rep(L,0,K){
		int ex=m-1-K;
		int mn=1e9,len=n-m+1;
		rep(j,0,ex) mn=min(mn,max(a[L+j+1],a[L+j+len]));
		ans=max(ans,mn);
	}
	cout<<ans<<endl;
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}