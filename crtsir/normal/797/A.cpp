#include<bits/stdc++.h>
using namespace std;
int n,k,x=2;
int main(){
	cin>>n>>k;
	vector<int>ans;
	while(n!=1&&ans.size()!=k-1){
		while(n%x!=0)x++;
		n/=x;
		ans.push_back(x);
	}
	if(ans.size()!=k-1||n==1)
		n=-1;
	else
		for(int i=0;i<k-1;i++)
			cout<<ans[i]<<' ';
	cout<<n;
}