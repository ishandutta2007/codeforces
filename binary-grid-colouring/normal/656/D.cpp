#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int main()
{
  	ll p;
    cin>>p;
    int ans=0;
    while(p)
	{
        if (p%8==1) ans++;
        p/=8;
    }
    cout<<ans<<endl;
    return 0;
}