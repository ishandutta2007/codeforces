#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];
bool u[123],v[123];
int main()
{
	int n;
	cin>>n;
	int s,d,w;
	int sum = 0;
	int ans = 0;
	for(int i=1;i<=n;i++){
		cin>>s>>d>>w;
		if(u[s] || v[d]){
			ans += w;
			u[d] = v[s] = true;
		}
		else
		{
			u[s] = v[d] = true;
		}
		sum += w;
	}
	cout<<min(ans,sum-ans)<<endl;
	return 0;
}