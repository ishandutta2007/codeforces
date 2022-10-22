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
int i,j,k,n,m,T,ans[maxn];
int main(){
	cin>>T;
	while(T--){
		int a,b;
		cin>>n>>a>>b;
		if(a+b>n-2 || a>(n-1)/2 || b>(n-1)/2 || abs(a-b)>1)puts("-1");
		else{
			if(a!=b){
				for(i=1;i<=max(a,b);i++){
					ans[2*i-1]=i;
					ans[2*i]=n-i+1;
				}
				for(i=2*max(a,b)+1;i<=n;i++)ans[i]=-i+n+max(a,b)+1;
			}else
			if(a==b){
				for(i=1;i<=a;i++){
					ans[2*i-1]=i;
					ans[2*i]=n-i+1;
				}
				for(i=2*a+1;i<=n;i++)ans[i]=i-a;
			}
//			for(i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
			if(b>a)for(i=1;i<=n;i++)ans[i]=n-ans[i]+1;
			for(i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
		}
	}
	return 0;
}