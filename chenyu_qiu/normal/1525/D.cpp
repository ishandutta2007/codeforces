#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t1,n,i,j,s,flag,m,a[10010],b[10010],f[10010];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)if(a[i]==1)b[++m]=i;
	for(i=1;i<=n;i++){
		s+=1-a[i];
		if(!a[i]){
			f[s]=1e9;
			for(j=min(m-1,s-1);j>=0;j--)f[j+1]=min(f[j+1],f[j]+abs(i-b[j+1]));
		}
	}
	printf("%d",f[m]);
}