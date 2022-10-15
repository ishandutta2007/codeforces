#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
map<string,int>mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        mp[a]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        if(mp[a])
            mp[a]--;
        else
            ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

3 10
4 6 7


**/