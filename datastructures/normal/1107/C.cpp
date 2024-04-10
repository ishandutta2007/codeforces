#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define mod 1000000007
using namespace std;
int n,k,a[1000005],len,c[1000005],sum[1000005],ans;
char s[1000005];
int head,tail,q[1000005],f[1000005];
inline int dp(){
	int ans=0;
	sort(c+1,c+1+len);
	for (int i=1;i<=len&&i<=k;i++)ans+=c[len-i+1];
	return ans;
}
signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		int j=i;
		while(s[j]==s[i])j++;
		j--;
		len=0;
		for (int k=i;k<=j;k++)c[++len]=a[k];
		ans+=dp();
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}

//f[i]=f[j-1]+sum[i]-sum[j]=f[j-1]-sum[j]+sum[i] (i-j<=k)