#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int n,a[103];
		cin>>n;
		map<int,int>mp;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];a[i]=fabs(a[i]);mp[a[i]]++;
			if(mp[a[i]]<=2&&(a[i]!=0||mp[a[i]]==1))ans++;
		}
		cout<<ans<<endl;
		
	}
}