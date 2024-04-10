#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,l;
    cin>>n>>l;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int bst=0;
    for(int t=l;t<=100;t++)
    {
        int cur=0;
        for(int i=0;i<n;i++)
            cur+=v[i]/t;
        bst=max(bst,t*cur);
    }
    cout<<bst<<"\n";
    return 0;
}
/**

**/