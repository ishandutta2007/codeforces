#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i].first);
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    vector<int> res(n);
    int idx=-1;
    for(pair<int,int> p:v)
    {
        res[p.second]=max(-1,idx-p.second-1);
        idx=max(idx,p.second);
    }
    for(int i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
    return 0;
}