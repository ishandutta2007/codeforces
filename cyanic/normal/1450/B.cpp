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

const int N=105;
int x[N],y[N],n,K;

void rmain(){
	read(n),read(K);
	rep(i,1,n){
		read(x[i]);
		read(y[i]);
	}
	rep(i,1,n){
		int flag=1;
		rep(j,1,n){
			flag&=(abs(x[i]-x[j])+abs(y[i]-y[j])<=K);
		}
		if(flag){
			puts("1");
			return;
		}
	}
	puts("-1");
}

int main(){
	int T;
	read(T);
	for(;T;T--) rmain();

	return 0;
}