#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
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

int a,b;

int main(){
	read(a),read(b);
	rep(x,1,a-1){
		int y=sqrt(a*a-x*x+0.5);
		if(y*y+x*x!=a*a) continue;
		int g=__gcd(a,b);
		if(y%(a/g)) continue;
		if(x%(a/g)) continue;
		int xx=x/(a/g)*(b/g);
		int yy=y/(a/g)*(b/g);
		if(y==xx) continue;
		puts("YES");
		printf("%d %d\n",-x,y);
		puts("0 0");
		printf("%d %d\n",yy,xx);
		return 0;
	}	
	puts("NO");
	return 0;
}