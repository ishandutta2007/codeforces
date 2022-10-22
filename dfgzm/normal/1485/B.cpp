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
ll i,j,k,n,m,q,T,a[maxn];
int main(){
	cin>>n>>q>>k;
	for(i=1;i<=n;i++)a[i]=read();
	for(i=1;i<=q;i++){
		int l=read(),r=read();
		if(l==r)printf("%lld\n",max(0ll,k-1));
		else{
			printf("%lld\n",k+a[r]-a[l]-2*(r-l+1)+1);
		}
	}
	return 0;
}