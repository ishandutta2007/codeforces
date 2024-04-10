#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
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

const int N=2000005;
ll x[N],y[N],n,sx,sy;

int main(){
	read(n);
	if(n&1){
		puts("NO");
		return 0;
	}
	rep(i,1,n){
		read(x[i]),read(y[i]);
		sx+=x[i]*2,sy+=y[i]*2;
	}
	rep(i,1,n/2){
		if(n*(x[i]+x[i+n/2])!=sx){
			puts("NO");
			return 0;
		}
		if(n*(y[i]+y[i+n/2])!=sy){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}