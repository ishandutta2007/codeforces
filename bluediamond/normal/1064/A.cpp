/**
   
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v[3],ans=0;
    cin>>v[0]>>v[1]>>v[2];
    while(1)
    {
        sort(v,v+3);
        if(v[0]+v[1]>v[2])
        {
            break;
        }
        ans++;
        v[1]++;
    }
    cout<<ans<<"\n";
    return 0;
}
/**
**/