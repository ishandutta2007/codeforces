#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[1003],b[1003];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<m;i++)
			cin>>b[i];
		int ans=-1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i]==b[j])
					ans=a[i];
		if(ans==-1)
			cout<<"NO\n";
		else
			cout<<"YES\n"<<1<<' '<<ans<<endl;
	}
}