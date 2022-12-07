#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, su[2]={0, 0};
    cin>>n;
    vector <pair <int, int> > ve;
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%lld", &x);
            ve.push_back(make_pair(x, i)), su[i]+=x;
        }
    }
    sort(ve.begin(), ve.end());
    for(int a=0; a<n; a++)
    {
        for(int i=0; i<2; i++)
        {
            if(ve.back().second!=i) su[i^1]-=ve.back().first;
            ve.pop_back();
        }
    }
    cout<<su[0]-su[1];
}