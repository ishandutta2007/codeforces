#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666;
int n,a[N],s[N],len;char S[N];
ll b[N],res;
int main() {
	scanf("%s",S+1);n=strlen(S+1);
	rep(i,1,n)a[i]=S[i]-'0';
	int M=min(n,250);
	rep(k,1,M){
		rep(i,1,n)b[i]=1-a[i]*k;
		rep(i,1,n)b[i]+=b[i-1];
		sort(b,b+n+1);
		rep(i,0,n){
			int j=i;while(j+1<=n&&b[j+1]==b[i])j++;
			res+=1ll*(j-i+1)*(j-i)/2;i=j;
		}
	}
	rep(i,1,n){
		if(a[i])s[++len]=i;
		for(int j=len;j>=1&&(len-j+1)*(M+1)<=i;j--){
			int l=max(i-s[j]+1,(len-j+1)*(M+1)),r=i-s[j-1];
			if(l<=r)res+=r/(len-j+1)-(l-1)/(len-j+1);
		}
	}
	cout<<res<<endl;
	return 0;
}