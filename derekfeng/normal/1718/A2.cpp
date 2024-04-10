#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int tc,n,a[100004],f[100004];
map<int,int>mp;
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]^=a[i-1];mp.clear();mp[0]=0;
	for(int i=1;i<=n;i++)f[i]=min(f[i-1]+1,mp.count(a[i])?f[mp[a[i]]]+i-mp[a[i]]-1:inf),mp[a[i]]=i;
	printf("%d\n",f[n]);
}
int main(){
	scanf("%d",&tc);
	while(tc--)sol();
}