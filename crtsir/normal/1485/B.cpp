#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[100003],sum[100003];
int main(){
	cin>>n>>T>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		cout<<k+a[r]-a[l]-2*r+2*l-1<<endl;
	}
}