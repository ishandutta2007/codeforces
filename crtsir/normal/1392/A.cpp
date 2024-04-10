#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;bool ok=0;
		for(int i=0;i<n;i++)scanf("%d",a+i);
		for(int i=1;i<n;i++)
			ok|=(a[i]!=a[i-1]);
		if(ok)
			cout<<1<<endl;
		else
			cout<<n<<endl;
	}
}