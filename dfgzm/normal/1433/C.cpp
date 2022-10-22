#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=3e5 + 5;
int i,j,k,n,m,T,a[maxn];
int main(){
	T=read();
	while(T--){
		n=read();int Max=0,b=1;
		for(i=1;i<=n;i++)a[i]=read(),Max=max(Max,a[i]);
		a[0]=a[n+1]=Max;
		for(i=1;i<=n;i++){
			if(a[i]==Max && (a[i+1]!=Max || a[i-1]!=Max)){
				printf("%d\n",i);
				b=0;
				break;
			}
		}if(b)puts("-1");
		for(i=1;i<=n;i++)a[i]=0;
	} 
	return 0;
}