#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 233333, mo = 1e9+9;
int n,a,b,k,s[N];
char S[N];
int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
int inv(int a) {return power(a,mo-2);}
int calc(int l, int r) {
	ll res=0;
	rep(i,l,r) res+=1LL*s[i%k]*power(a,n-i)*power(b,i)%mo;
	return (res%mo+mo)%mo;
}
int solve(int a1, int q, int n) {
	if (q==1) return n;
	return 1LL*a1*(power(q,n)-1)%mo*inv(q-1)%mo;
}
int main() {
	read(n); read(a); read(b); read(k);
	scanf("%s",S); rep(i,0,k-1) s[i]=S[i]=='+'?1:-1;
	ll res=calc(n/k*k,n),A=calc(0,k-1);
	res+=A*solve(1,power(1LL*b*inv(a)%mo,k),n/k)%mo;
	cout<<(res%mo+mo)%mo;
	return 0;
}