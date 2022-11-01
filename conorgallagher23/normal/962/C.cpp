#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int Inf=1e9;
int n,len,nd[15],dig[15],ans=Inf;
bool check(int x){int y=sqrt(x);return y*y==x;}
int main(){
	scanf("%d",&n);
	if(check(n)){puts("0");return 0;}
	while(n)dig[++len]=n%10,n/=10;
	reverse(dig+1,dig+len+1);
	for(int s=1,nl,zf,res;s<(1<<len);s++){
		nl=res=0;zf=-1;
		for(int j=0;j<len;j++)if(s&(1<<j))nd[++nl]=dig[j+1];
		for(int j=1;j<=nl;j++)if(nd[j]){zf=j;break;}
		if(zf>1||zf==-1)continue;
		for(int j=1;j<=nl;j++)res=res*10+nd[j];
		if(check(res))ans=min(ans,len-nl);
	}
	printf("%d\n",ans>=Inf?-1:ans);
	return 0;
}