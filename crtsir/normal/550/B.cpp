#include<bits/stdc++.h>
using namespace std;
int diff[17],ans,n,r,l,x;
void check(vector<int>v)
{
    int tot=0;
    for(int i=0;i<v.size();i++)
        tot+=diff[v[i]];
    if(diff[v[v.size()-1]]-diff[v[0]]>=x)
        if(tot>=l&&tot<=r)
            ans++;
}
int main()
{
    cin>>n>>l>>r>>x;
    for(int i=0;i<n;i++)
        cin>>diff[i];
    sort(diff,diff+n);
    for(int i=1;i<(1<<n);i++)
    {
        vector<int>v;
        for(int j=0;j<n;j++)
            if((i&(1<<j)))
                v.push_back(j);
        check(v);
    }
    cout<<ans;
}