#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
map<int, int>mp[123456];

int p[123456],dp[123456];
int res[123456];

int main()
{
    int v,c,l,r,n;      
    cin>>n;
    int cur=0;
    for(int i = 1; i<=n; i++)
	{
        cin>>v>>c>>l>>r;
        if(r + c < 123456)
		{
            int idx = mp[l][r+c];
            if(idx || l==0)
			{
                dp[i] = dp[idx] + v;
                p[i] = idx;
                if(dp[i] > dp[ mp[l + c][r] ])
				{
                    mp[l+c][r] = i;
                }
                if(r==0 && dp[i] > dp[cur])
				{
                    cur = i;
                }
            }
        }
    }
    int num=0;
    while(cur)
	{
        res[num] = cur;
        cur = p[cur];
        ++num;
    }
    cout<<num<<endl;
    for(int i = num-1; i>=0;--i)
	{
       cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}