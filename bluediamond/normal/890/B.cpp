#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,ans=0,bst=1e9;
    cin>>n;
    map<int,int>lst;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int cur=i-lst[x];
        lst[x]=i;
    }
    for(auto itr:lst)
    {
        if(itr.second<bst)
        {
            ans=itr.first;
            bst=itr.second;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**


**/