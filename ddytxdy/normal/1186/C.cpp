#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
char a[N],b[N];int la,lb,s[N],x,ans;
int main(){
	scanf("%s%s",a+1,b+1);
	la=strlen(a+1);lb=strlen(b+1);
	for(int i=1;i<=la;i++)s[i]=s[i-1]+a[i]-'0';
	for(int i=1;i<=lb;i++)x+=b[i]-'0';
	for(int i=lb;i<=la;i++)if((s[i]-s[i-lb]+x)%2==0)ans++;
	printf("%d\n",ans);
	return 0;
}