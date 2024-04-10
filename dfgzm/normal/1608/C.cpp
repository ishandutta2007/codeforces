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
int i,j,k,n,m,T,a[maxn],b[maxn],A[maxn],B[maxn],wa[maxn],wb[maxn],tmp[maxn],id[maxn];
int sa[maxn],sb[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)sa[i]=a[i]=read();
		for(i=1;i<=n;i++)sb[i]=b[i]=read();
		sort(sa+1,sa+1+n);
		sort(sb+1,sb+1+n);
		for(i=1;i<=n;i++)a[i]=lower_bound(sa+1,sa+1+n,a[i])-sa;
		for(i=1;i<=n;i++)b[i]=lower_bound(sb+1,sb+1+n,b[i])-sb;
		for(i=1;i<=n;i++)A[a[i]]=b[i],id[a[i]]=i;
		for(i=1;i<=n;i++)B[b[i]]=a[i];
		for(i=1;i<=n;i++)wa[i]=max(wa[i-1],A[i]);
		for(i=1;i<=n;i++)wb[i]=max(wb[i-1],B[i]);
		int now=0,t=0;
		while(now!=n){
			now++;t=now;
			int last=now;
			do{
				last=now;
				now=max(now,wb[wa[now]]);
			}while(last!=now);
		}
		for(i=1;i<=n;i++)tmp[i]=0;
		for(i=t;i<=n;i++)tmp[id[i]]=1;
		for(i=1;i<=n;i++)if(tmp[i])putchar('1');else putchar('0');puts("");
	}
	return 0;
}