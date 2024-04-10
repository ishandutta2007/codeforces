#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		long long ans=0,cnt1=0,cnt2=n*k;
		for(int i=0;i<k*n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<k;i++){
			vector<int>V;
			for(int j=0;j<(n-1)/2;j++)
				V.push_back(a[cnt1++]);
			for(int j=(n-1)/2;j<n;j++)
				V.push_back(a[--cnt2]);
			sort(V.begin(),V.end());
			ans+=V[(n-1)/2];
//			cout<<V[(n-1)/2]<<' ';
		}
		cout<<ans<<endl;
	}
}