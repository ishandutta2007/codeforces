#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
char s[1000005];
int n,x,y,a[1000005];
int pre[1000005][2],suf[1000005][2],sum;
int c[100005],tot;
int ans;
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	cin>>x>>y;
	for (int i=1;i<=n;i++)
		if (s[i]=='0'||s[i]=='1')a[i]=s[i]-'0';
		else a[i]=-1;
	if (x>y){
		swap(x,y);
		for (int i=1;i<=n;i++)
			if (a[i]!=-1)a[i]=1-a[i];
	}
	for (int i=1;i<=n;i++){
		pre[i][0]=pre[i-1][0];
		pre[i][1]=pre[i-1][1];
		if (a[i]!=-1)pre[i][a[i]]++;
	}
	for (int i=n;i>=1;i--){
		suf[i][0]=suf[i+1][0];
		suf[i][1]=suf[i+1][1];
		if (a[i]!=-1)suf[i][a[i]]++; 
	}
	for (int i=1;i<=n;i++){
		if (a[i]==0)sum+=y*pre[i-1][1];
		if (a[i]==1)sum+=x*pre[i-1][0];
		if (a[i]==-1)sum+=x*pre[i-1][0]+y*suf[i+1][0],c[++tot]=(y*pre[i-1][1]+x*suf[i+1][1])-(x*pre[i-1][0]+y*suf[i+1][0]);
	}
	ans=sum;
	for (int i=1;i<=tot;i++){
		sum+=c[i];
		ans=min(ans,sum+x*i*(tot-i));
	}
	cout<<ans<<endl;
	return 0;
}