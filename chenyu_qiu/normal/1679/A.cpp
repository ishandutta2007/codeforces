#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
int main(){
	int t=getint();
	while(t--){
		ll x;scanf("%lld",&x);
		if(x<4||(x&1)){puts("-1");continue;}
		ll ans1,ans2;
		ans1=x/6;
		if(x%6)++ans1;
		ans2=x/4;
		printf("%lld %lld\n",ans1,ans2);
	} 
	return 0;
}