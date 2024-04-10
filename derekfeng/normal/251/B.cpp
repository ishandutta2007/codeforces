#include<bits/stdc++.h>
using namespace std;
int n,k,q[103],s[103];
int p[103],P[103];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	bool flg=1;
	for(int i=1;i<=n;i++)p[i]=i,flg&=(s[i]==i);
	if(flg){puts("NO");return 0;}
	int ok1=k+1,ok2=k+1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)P[j]=p[q[j]];
		flg=1;
		for(int j=1;j<=n;j++)flg&=(P[j]==s[j]);
		if(flg){
			if(((k^i)&1)^1)if(i>1||k==1){puts("YES");return 0;}
			ok1=i;break;
		}
		memmove(p+1,P+1,n*4);
	}
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)P[q[j]]=p[j];
		flg=1;
		for(int j=1;j<=n;j++)flg&=(P[j]==s[j]);
		if(flg){
			if(((k^i)&1)^1)if(i>1||k==1){puts("YES");return 0;}
			ok2=i;break;
		}
		memmove(p+1,P+1,n*4);
	}
	if(ok1<=k)if(((k^ok1)&1)^1)if(ok2>1){puts("YES");return 0;}
	if(ok2<=k)if(((k^ok2)&1)^1)if(ok1>1){puts("YES");return 0;}
	puts("NO");
}