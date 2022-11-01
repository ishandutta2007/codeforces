#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> a(n);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].first,&a[i].second);
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<n;i++)
        {
            if(o==i) continue;
            v.push_back({a[o].first-a[i].first,a[o].second-a[i].second});
        }
    }
    long long res=0;
    sort(v.begin(),v.end());
    int idx=0;
    v.push_back({-1,-1});
    while(idx<(int)v.size())
    {
        long long cnt=0;
        pair<int,int> now=v[idx];
        while(idx<(int)v.size()&&v[idx]==now)
        {
            idx++;
            cnt++;
        }
        res+=(cnt*(cnt-1)/2);
    }
    printf("%I64d\n",res/4);
    return 0;
}