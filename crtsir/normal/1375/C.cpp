#include<bits/stdc++.h>
using namespace std;
int T,n,a[300003];
int main(){cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",a+i);
		if(a[n-1]<a[0])cout<<"NO\n";else cout<<"YES\n";
	}
}