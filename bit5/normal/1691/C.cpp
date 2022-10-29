#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,m;
char str[N];
inline void work(){
	n=read(),m=read();
	scanf("%s",str+1);
	int p1=0,p2=0,cnt=0;
	for(int i=1;i<=n;i++)cnt+=str[i]=='1';
	if(!cnt){puts("0");return;}
	for(int i=1;i<=n;i++)
		if(str[i]=='1'){p1=i;break;}
	if(cnt==1){
		if(n-p1<=m)puts("1");
		else if(p1-1<=m)puts("10");
		else puts("11");
		return;
	}
	for(int i=n;i;i--)
		if(str[i]=='1'){p2=i;break;}
	int ans=11*cnt;
	if(n-p2<=m)ans-=10,m-=n-p2;
	if(p1-1<=m)ans--;
	printf("%d\n",ans);
}
int main(){	
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}