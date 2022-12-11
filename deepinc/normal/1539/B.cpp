#include<bits/stdc++.h>
using namespace std;
int n,k,a[111111]; char s[111111];
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;++i)a[i]=a[i-1]+s[i]-'a'+1;
	for(int i=1,l,r;i<=k;++i)scanf("%d%d",&l,&r),printf("%d\n",a[r]-a[l-1]);
}