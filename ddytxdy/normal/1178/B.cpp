#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+50;
int len,f1[N],f2[N];char c[N];LL ans;
int main(){
	scanf("%s",c+1);
	len=strlen(c+1);
	for(int i=1;i<=len;i++)if(c[i]=='v'&&c[i-1]=='v')f1[i]++;
	for(int i=1;i<=len;i++)f1[i]+=f1[i-1];
	for(int i=len;i;i--)if(c[i]=='v'&&c[i+1]=='v')f2[i]++;
	for(int i=len;i;i--)f2[i]+=f2[i+1];
	for(int i=1;i<=len;i++)if(c[i]=='o')ans+=1ll*f1[i-1]*f2[i+1];
	cout<<ans;
	return 0;
}