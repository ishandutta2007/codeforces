#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct info
{
    int i;
    int x;
};

bool cmp(info a,info b)
{
    return a.x<b.x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<info>v(n);
    for(int i=0;i<n;i++)
    {
        v[i].i=i;
        cin>>v[i].x;
    }
    vector<int>ans(n);
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
        ans[v[i].i]=i%2;
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
/**
**/