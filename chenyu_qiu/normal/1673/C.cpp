#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
#define mod 1000000007
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
#define maxn 40040
int dp[maxn];
bool check(int x){
	int tmp[10],l=1,p=0;
	for(;l<=x;l*=10)tmp[++p]=x/l%10;
	for(int i=1;i<=p;++i)if(tmp[i]!=tmp[p-i+1])return 0;
	return 1; 
}
int main(){
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<maxn;++i){
		if(!check(i))continue;
		for(int j=i;j<maxn;++j)dp[j]=(dp[j]+dp[j-i])%mod;
	}
	int t=getint();
	while(t--)printf("%d\n",dp[getint()]);
	return 0;
}