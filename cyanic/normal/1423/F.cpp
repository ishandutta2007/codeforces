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

const int N=200005;
int a[N],b[N],p[N],n,K;
ll sum,aim,now;

int main(){
	read(n),read(K);
	rep(i,1,K){
		read(a[i]),read(b[i]);
		p[i]=i;
		sum+=b[i];
	}
	if(sum>n){
		puts("-1");
		return 0;
	}
	if(sum<n){
		puts("1");
		return 0;
	}
	aim=(ll)n*(n-1)/2%n;
	ll acc=0;
	sort(p+1,p+K+1,[&](int x,int y){
		return a[x]<a[y];
	});
	p[K+1]=K+1;
	a[K+1]=n+1;
	rep(i,1,K){
		acc=(acc+b[p[i]])%n;
		now=(now+acc*(a[p[i+1]]-a[p[i]]))%n;
	}
	if(now!=aim){
		puts("-1");
	}
	else{
		puts("1");
	}
	return 0;
}