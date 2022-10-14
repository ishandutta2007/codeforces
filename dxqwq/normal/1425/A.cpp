#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
    int w=0,f=1;
    char c=' ';
    while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
    while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
    return w*f;
}
int T,n;
int a[55]={0,1,1,2,3,2,4,3,5,4,8,3,9,4,11,4,12,5,14,5,15,6,19,4,20,5,22,5,23,6,26,5,27,6,29,6,30,7,33,6,34,7,36,7,37,8,42,5,43,6,45};
signed main(){
	T=read();
	while(T--){
		int ans=0;
		n=read();
		for(int i=1;n;i^=1){
			if(n<30){
				ans+=(i?a[n]:n-a[n]);
				break;
			}
			if(n%2==1)n--,ans+=i;
			else if(n%4==0)n--,ans+=i;
			else if(n%4==2)ans+=i*n/2,n/=2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}