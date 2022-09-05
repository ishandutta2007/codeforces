#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 555555;
int n;char s[N],t[N];int f[4][4],cnt[5];

int main() {
	read(n);scanf("%s%s",s+1,t+1);
	rep(i,0,3)rep(j,0,3){
		int a=(i&2)>0,b=i&1,c=(j&2)>0,d=j&1;
		f[i][j]=((a|b)!=(c|b))||((c|d)!=(a|d));
	//	if(f[i][j])printf("%d %d %d %d\n",a,b,c,d);
	}
	rep(i,1,n)cnt[(s[i]-'0')*2+(t[i]-'0')]++;ll res=0;
	rep(i,0,3)rep(j,i+1,3)res+=1LL*f[i][j]*cnt[i]*cnt[j];
//	printf("%d\n",res);
	rep(i,0,3)res+=1LL*f[i][i]*cnt[i]*(cnt[i]-1)/2;
	printf("%lld\n",res);
	return 0;
}