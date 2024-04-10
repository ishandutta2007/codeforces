#include <bits/stdc++.h>

using namespace std;

int n,key,last,cur,ans;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>key;
        if(cur==0)
            cur++;
        else
        {
            if(last<key)
                cur++;
            else
                cur=1;
        }
        last=key;
        ans=max(ans,cur);
    }
    cout<<ans;
	return 0;
}
/**


**/