#include <bits/stdc++.h>
using namespace std;
int main()
{

	string c;
	cin>>c;
	string ans = regex_replace(c,regex("(/)+"),"/");
	
	if(ans[ans.size()-1]=='/' and ans.size()>1)
	{
    	ans[ans.size()-1]=' ';
	}
	cout<<ans<<endl;;
}