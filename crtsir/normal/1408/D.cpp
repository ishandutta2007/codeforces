#include<bits/stdc++.h>
using namespace std;
int n,m,a[2003],b[2003],c[2003],d[2003],F[1000003],ans=2000003;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%d%d",a+i,b+i);
	for(int i=0;i<m;i++)
		scanf("%d%d",c+i,d+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(c[j]-a[i]>=0)
				F[c[j]-a[i]]=max(F[c[j]-a[i]],d[j]-b[i]+1);
	for(int i=1000001;i>=0;i--)
		F[i]=max(F[i],F[i+1]);
	for(int i=0;i<1000003;i++)
		ans=min(ans,i+F[i]);
	cout<<ans;
}