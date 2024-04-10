#include <bits/stdc++.h>
#define int long long
using namespace std;
bool comp(pair <int, int> a, pair <int, int> b)
{
    if(a.second!=b.second) return a.second>b.second;
    else return a.first<b.first;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        ar[a].first=x;
        ar[a].second=0;
        while(x%3==0)
        {
            ar[a].second++, x/=3;
        }
    }
    sort(ar, ar+n, comp);
    for(int a=0; a<n; a++) cout<<ar[a].first<<" ";
}