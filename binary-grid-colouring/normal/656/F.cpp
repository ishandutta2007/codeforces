#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int main()
{
  string s;
  cin>>s;
  int ans=1;
  for(int i=1;i<=6;i++)
  {
  	if(s[i]=='1')
    {
	  	ans+=10;
		i++;
	}
	else
      ans+=s[i]-'0';
  }
  cout<<ans<<endl;
  return 0;
}