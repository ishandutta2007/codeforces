#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define clr(x) memset(x,0,sizeof x)
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

const int N=505;
int f[N][N],n,K,c;
vi ans;

int main(){
	read(n),read(K);
	f[0][0]=1;
	rep(i,1,n){
		read(c);
		per(a,K,0) per(b,K-a,0){
			if(!f[a][b]||a+b+c>K) continue;
			f[a+c][b]=f[a][b+c]=1;
		}
	}
	rep(i,0,K){
		if(f[i][K-i]) ans.pb(i);
	}
	printf("%d\n",SZ(ans));
	for(auto x:ans){
		printf("%d ",x);
	}
	puts("");
	return 0;
}