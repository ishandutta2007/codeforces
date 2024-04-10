#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define mod 998244353
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
char s[500050];
string str[500050];
int ans[500050];
void calc_ans(int o,int l,int r){
	if(l==r){ans[o]=1;str[o].push_back(s[o]);return;}
	int mid=(l+r)>>1,ls=o<<1,rs=o<<1|1;
	calc_ans(ls,l,mid);
	calc_ans(rs,mid+1,r);
	if(str[ls]!=str[rs])ans[o]=2ll*ans[ls]*ans[rs]%mod;
	else ans[o]=1ll*ans[ls]*ans[rs]%mod;
	if(str[ls]>str[rs])swap(ls,rs);
	str[o].push_back(s[o]);
	str[o]=str[o]+s[o]+str[ls]+str[rs];
}
int main(){
	int n=getint();
	cin>>(s+1);
	calc_ans(1,1,1<<(n-1));
	printf("%d\n",ans[1]);
	return 0;
}