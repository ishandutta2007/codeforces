#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int main()
{
	string s;
	int ans=0;
	int r = 0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='('){
			r++;
		}
		else if(r!=0){
			r--;
			ans+=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}