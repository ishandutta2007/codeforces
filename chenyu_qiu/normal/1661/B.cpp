#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
#define mod 32768
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
inline int calc(int x){
	int ans=0;
	while(x)x=(x<<1)%mod,++ans;
	return ans;
}
int main(){
	int n=getint();
	for(int i=1;i<=n;++i){
		int ans=100,x=getint();
		for(int k=0;k<=50;++k){
			ans=min(ans,k+calc(x));
			++x;
			x%=mod;
		}
		printf("%d",ans);
		if(i<n)putchar(' ');
		else puts("");
	}
	return 0;
}