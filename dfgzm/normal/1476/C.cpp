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
int i,j,k,n,m,T;ll l[maxn],a[maxn],b[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)l[i]=read();
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=n;i++){
			b[i]=read();
			if(b[i]<a[i])swap(a[i],b[i]);
		}
		ll now=-1,ans=0;
		for(i=2;i<=n;i++){
			if(now!=-1 && (a[i]!=b[i]))
				now=max(now+a[i]-1+l[i-1]-b[i]+2,b[i]-a[i]);
			else now=b[i]-a[i];
			ans=max(ans,now+l[i]-1+2);
		}cout<<ans<<endl;
	}
	return 0;
}