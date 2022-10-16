#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ans=-1;
		for(int i=0;i<n;i++)
			if(a[i]!=i)
				ans&=a[i];
		cout<<ans<<endl;
	}
}