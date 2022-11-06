#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[102],b[102];
bool f[102][10002];
int main(){
	int t,n,i,j,s;
	ll ans=0;
	read(t);
	while(t--){
		read(n);
		ans=0;s=0;
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			ans=ans+1LL*a[i]*a[i];
			s+=a[i];
		}
		for(i=1;i<=n;++i){
			scanf("%d",&b[i]);
			ans=ans+1LL*b[i]*b[i];
			s+=b[i];
		}
		for(i=0;i<=n;++i){
			for(j=0;j<=n*100;++j)f[i][j]=0;
		}
		f[0][0]=1;
		for(i=1;i<=n;++i){
			for(j=n*100;j>=a[i];--j)f[i][j]|=f[i-1][j-a[i]];
			for(j=n*100;j>=b[i];--j)f[i][j]|=f[i-1][j-b[i]];
		}
		int mx=s,x=-1;
		for(i=0;i<=n*100;++i){
			if(f[n][i]){
				if(abs(2*i-s)<mx){
					mx=abs(2*i-s);
					x=i;
				}
			}
		}
		ans*=(n-2);
		ans=ans+1LL*x*x+(s-x)*(s-x);
		printf("%lld\n",ans);
		
	}
	return 0;
}