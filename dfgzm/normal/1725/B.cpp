#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
int n,D,a[maxn],ans;
signed main(){
	n=read(),D=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=n,p=0;i>=1;i--){
		if(p>=i)break;
		if(a[i]*(i-p)<=D)break;
		p+=D/a[i];++ans;
	}cout<<ans<<endl;
    return 0;
}