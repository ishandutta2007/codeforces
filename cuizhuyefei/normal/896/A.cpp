#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 200003;
ll len[N],n,k;
string s="_What are you doing at the end of the world? Are you busy? Will you save us?";
string t="_What are you doing while sending \"\"? Are you busy? Will you send \"\"?";

inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
//What are you doing at the end of the world? Are you busy? Will you save us?
char getans(int n, ll k) {
	if (n==0) return s[k];
	if (k<=34) return t[k]; //update!
	ll Len=len[n-1]+34;
	if (k<=Len) return getans(n-1,k-34);
	k-=Len; //printf("%lld %c\n",k,t[64]);
	if (k<=32) return t[k+34]; //+34
	k-=32; if (k<=len[n-1]) return getans(n-1,k);
	k-=len[n-1]; return k==2 ? '?' : '\"';
}
int main() {
//	freopen("1.in","r",stdin);
//	rep(i,1,t.size()-1) printf("%c",t[i]);
	len[0]=75;
	rep(i,1,55) len[i]=len[i-1]*2+68;
	rep(i,56,N-2) len[i]=5e18;
	ll q; read(q);
	while (q--) {
		read(n); read(k);
		if (k>len[n]) {printf("."); continue;}
		printf("%c",getans(n,k));
	}
	return 0;
}