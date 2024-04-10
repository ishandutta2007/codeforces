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
const int N = 233333;
char s[N],t[N];int n,m,nxt[N],lcp[N],val[N],z[N];ll res;
void z_algo(char *s, int n){
	int id=0;
	rep(i,2,n){
		if(id+z[id]>i)z[i]=min(id+z[id]-i,z[i-id+1]);
		while(i+z[i]<=n&&s[i+z[i]]==s[1+z[i]])z[i]++;
		if(i+z[i]>id+z[id])id=i;
	}
}
int main() {
	scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
	for(int i=2,j=0;i<=m;i++){
		while(j&&t[i]!=t[j+1])j=nxt[j];
		if(t[i]==t[j+1])j++;nxt[i]=j;
	}
//	while(lcp+1<=min(n,m)&&s[lcp+1]==t[lcp+1])lcp++;
	
	rep(i,1,n)t[m+i]=s[i];z_algo(t,m+n);
	rep(i,1,n)lcp[i]=z[m+i];
	rep(i,2,n)val[lcp[i]]++;
	per(i,n,1)val[i]+=val[i+1];
	rep(y,1,m){
		int z=nxt[y];
		res+=!z?n:n-(val[y-z]);//-(lcp>=y-z));
	}
	cout<<res;
	return 0;
}