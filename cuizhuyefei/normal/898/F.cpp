#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<queue>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 1000004;
const ll mo = 998244353;
int n;
char s[N];
ll val[N],mi[N];
inline ll mul(ll a, ll n) {
	ll ans=0;
	/*while (n) {
		if (n&1) (ans+=a)%=mo;
		a=(a+a)%mo;
		n>>=1;
	}*/
	return ans;
}
inline ll Hash(int a, int b) {
	a--;
	return (val[b]-val[a]*mi[b-a]%mo+mo)%mo;
}
inline bool judge(int a, int b, int c) {
	if (a<=0||b<=0||c<=0||a>c||b>c) return 0;
	if (c>a+1&&c>b+1) return 0;
	if (s[a+1]=='0'&&b!=1||s[n-c+1]=='0'&&c!=1) return 0;
//	if (a==3&&b==2&&c==3) printf("!! %lld %lld %lld\n",Hash(1,a),Hash(1+a,b+a),Hash(n-c+1,n));
	return ((Hash(1,a)+Hash(a+1,a+b))%mo)==Hash(n-c+1,n);
}
inline void print(int a, int b, int c) {
	int p=0; //printf("[%d %d %d]\n",a,b,c);
	rep(i,1,a) printf("%c",s[++p]); putchar('+');
	rep(i,1,b) printf("%c",s[++p]); putchar('=');
	rep(i,1,c) printf("%c",s[++p]);	
	exit(0);
}
int main() {
	scanf("%s",s+1); n=strlen(s+1);
	rep(i,1,n) val[i]=(val[i-1]*10+s[i]-'0')%mo;
	mi[0]=1; rep(i,1,n) mi[i]=mi[i-1]*10%mo;
	rep(i,1,n) {
		int j=i;
		if (judge(j,n-j-i,i)) print(j,n-j-i,i);
		if (judge(n-j-i,j,i)) print(n-j-i,j,i);
		j=i-1;
		if (judge(j,n-j-i,i)) print(j,n-j-i,i);
		if (judge(n-j-i,j,i)) print(n-j-i,j,i);
	}
	return 0;
}