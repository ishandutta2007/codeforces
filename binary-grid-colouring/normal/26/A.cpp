#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

bool check(int n)
{
	if(n<2)return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
 } 
int main()
{
	//cout<<check(11)<<endl;
	int n;
	cin>>n;
	int ans = 0;
	for(int k=1;k<=n;k++)
	{
		//int limit = sqrt(k);
		int cnt = 0;
		for(int i=1;i<=k;i++)
		{
			if(k%i==0)
			{
				if(check(i))
				{
					cnt++;
				}	
			}	
		}
		if(cnt==2)
		{
			//cout<<k<<endl;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;	
}