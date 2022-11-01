#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<pair<int,int>> v(2*n);
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        v[2*i]={l,0};
        v[2*i+1]={r,1};
    }
    sort(v.begin(),v.end());
    vector<pair<int,int>> res;
    int cnt=0;
    int idx=0;
    while(idx<2*n)
    {
        int t=cnt;
        int now=v[idx].first;
        while(idx<2*n&&v[idx]==make_pair(now,0))
        {
            idx++;
            cnt++;
        }
        if(t<k&&cnt>=k) res.push_back({now,0});
        t=cnt;
        while(idx<2*n&&v[idx]==make_pair(now,1))
        {
            idx++;
            cnt--;
        }
        if(t>=k&&cnt<k) res.back().second=now;
    }
    printf("%d\n",(int)res.size());
    for(pair<int,int> p:res) printf("%d %d\n",p.first,p.second);
    return 0;
}