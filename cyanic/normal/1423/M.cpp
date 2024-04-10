#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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

/*
char BUF[1 << 22], *ST, *EN;
#define gc (ST == EN && (ST = BUF, EN = BUF + fread(BUF, 1, 1 << 21, stdin), ST == EN) ? EOF : *ST++)
*/
#define gc getchar()

template<class T> void read(T &x){
	int f=0; x=0; char ch=gc;
	for(;!isdigit(ch);ch=gc) f|=(ch=='-');
	for(;isdigit(ch);ch=gc) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=1000005;
int L[N],n,m,res=1e9+99;

int qry(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int ret;
	read(ret);
	return ret;
}

int main(){
	read(n),read(m);
	L[0]=1;
	rep(i,1,n){
		L[i]=L[i-1];
		int ini=qry(i,L[i]);
		int mn=ini;
		for(int j=L[i]+1;j<=m;j++){
			int now=qry(i,j);
			if(i>=2&&now>=ini) break;
			if(now<mn){
				mn=now;
				L[i]=j;
			}
		}
		res=min(res,mn);
	}
	printf("! %d",res);
	fflush(stdout);
	return 0;
}