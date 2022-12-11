#include<bits/stdc++.h>
using namespace std;
const int N=200;
char c[N];int a[N],len,ans;bool flag;
int main(){
	scanf("%s",c);len=strlen(c);
	for(int i=1;i<=len;i++)a[i]=c[len-i]-'0';
	for(int i=1;i<len;i++)if(a[i])flag=1;
	ans=len/2;
	if((len&1)&&flag)ans++;
	printf("%d\n",ans);
	return 0;
}