#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m,ta,tb,k,i,j,ans=0,a[220000],b[220000];
	cin>>n>>m>>ta>>tb>>k;
 
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<m;i++){
		cin>>b[i];
	} 	
	if(k>=n||k>=m){
		cout<<-1;
		return 0;
	}
	for(i=0;i<=k;i++){
		j=lower_bound(b,b+m,a[i]+ta)-b+k-i;
		if(j>=m){
			cout<<-1;
			return 0;
		}
		ans=max(ans,b[j]+tb);
	}
	cout<<ans;
	return 0;
}