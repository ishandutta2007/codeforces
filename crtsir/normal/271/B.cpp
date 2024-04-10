#include<bits/stdc++.h>
using namespace std;
bool isprime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
set<int>s;
int n,m,x[503][503],ans=1036372536;
int main(){
	for(int i=2;i<=100003;i++)
		if(isprime(i))
			s.insert(i);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>x[i][j];
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=0;j<m;j++)
			sum+=*s.lower_bound(x[i][j])-x[i][j];
		ans=min(ans,sum);
	}
	for(int i=0;i<m;i++)
	{
		int sum=0;
		for(int j=0;j<n;j++)
			sum+=*s.lower_bound(x[j][i])-x[j][i];
		ans=min(ans,sum);
	}
	cout<<ans;
}