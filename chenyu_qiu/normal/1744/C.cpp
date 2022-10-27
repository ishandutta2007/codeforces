#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//#define int long long 
int t,n,q;
const int N = 1e5+10,M = N*32;
typedef long long ll;
typedef pair<int,int>PII;
 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		char c;
		cin>>n>>c;
		string s;
		cin>>s;
		if(c=='g'){
			cout<<0<<endl;
			continue;
		}
		s+=s;
		vector<int>v;
		for(int i=0;i<=n*2-1;i++)if(s[i]=='g')v.push_back(i);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==c){
				int r=upper_bound(v.begin(),v.end(),i)-v.begin();
				ans=max(ans,v[r]-i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}