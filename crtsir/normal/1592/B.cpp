#include<bits/stdc++.h>
using namespace std;
int T,n,x,a[100003],b[100003];
int main(){
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&x);
		for(int i=0;i<n;i++)
			scanf("%d",a+i),b[i]=a[i];
		sort(b,b+n);bool ok=1;
		for(int i=n-x;i<x;i++)
			if(b[i]!=a[i])
				ok=0;
		if(ok)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}