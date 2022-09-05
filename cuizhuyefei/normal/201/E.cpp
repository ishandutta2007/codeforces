#include<bits/stdc++.h>
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const ll inf=1e18;
int n,m;
int main() {
	int T;read(T);
	while(T--){
		read(n);read(m);
		int l=0,r=n,res=0;
		while(l<=r){
			int mid=(l+r)>>1;ll cnt=0,cur=1,tot=1LL*m*mid;
			for(int i=0;i<=mid;i++){
				ll f=min(cur,i?tot/i:inf);
				tot-=1LL*f*i;cnt+=f;
				if(!f||tot<i||cnt>=n)break;
				cur=cur*(mid-i)/(i+1);
			}
			if(cnt>=n)res=mid,r=mid-1;else l=mid+1;
		}
		printf("%d\n",res);
	}
	return 0;
}