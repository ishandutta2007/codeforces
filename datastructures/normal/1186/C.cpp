#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char s[1000005],t[1000005];
int n,m,sum[1000005],num,ans;
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1); 
	for (int i=1;i<=n;i++)sum[i]=sum[i-1]+(s[i]=='1');
	for (int i=1;i<=m;i++)num+=(t[i]=='1');
	for (int i=m;i<=n;i++)
		if (abs(sum[i]-sum[i-m]-num)%2==0)ans++;
	cout<<ans<<endl;
	return 0;
}