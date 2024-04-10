#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
const ll inf=2e9+10;
int i,j,k,n,m,T,a[maxn],l[maxn],r[maxn];ll c[maxn];
int main(){
	cin>>T;
	while(T--){
		ll ans=0;
		cin>>n;
		int L=1e9+1,R=-1e9-1;
		int chs=0;
		ll costL=0,costR=0;
		for(i=1;i<=n;i++){
			l[i]=read();
			r[i]=read();
			c[i]=read();
			if(l[i]<L)costL=c[i];
			if(l[i]==L)costL=min(costL,c[i]);
			if(r[i]>R)costR=c[i];
			if(r[i]==R)costR=min(costR,c[i]);
			L=min(L,l[i]);
			R=max(R,r[i]);
			if(chs && (l[chs]!=L || r[chs]!=R))chs=0;
			if(l[i]==L && r[i]==R && (!chs || c[chs]>c[i]))chs=i;
			printf("%lld\n",min(chs?c[chs]:inf,costL+costR));
		}
	}
	return 0;
}