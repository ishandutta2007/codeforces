#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[80],sum,cur;
int n,a[105],num[105];
void sol(){
	scanf("%d",&n);int t=0;cur=0,sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	for(t=0;;t++){
		cur+=f[t];if(cur>=sum)break;
	}
	if(cur!=sum){puts("NO");return;}
	int lst=-1;
	for(t;~t;t--){
		int mx=-1,pos=-1;
		for(int i=1;i<=n;i++)if(a[i]>mx&&i!=lst)mx=a[i],pos=i;
		if(mx<f[t]){puts("NO");return;}
		a[pos]-=f[t],lst=pos;
	}
	puts("YES");
}
int main(){
	f[0]=f[1]=1;
	for(int i=2;i<80;i++)f[i]=f[i-1]+f[i-2];
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}