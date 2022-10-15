#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000;

int n,p,v[N+5];

ll sum=0,cur=0;

int bst=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<n;i++)
    {
        cur+=v[i];
        bst=max((ll)bst,cur%p+(sum-cur)%p);
    }
    cout<<bst<<"\n";
    return 0;
}