#include<bits/stdc++.h>
using namespace std;
int vis[1005];
int pre[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(2*n);
    int pos=0;
    bool suc=0;
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
        if(a[i]==1) pos=i;
    }
    vector<int> tar(2*n);
    int ans=1e9;
    int cur=0;
    int cnt=0;
    auto aa=a;
    while(aa[0]!=1)
    {
        if(cur==0)
        {
            for(int i=0;i<n;i++) swap(aa[i],aa[i+n]);
        }
        else{
            for(int i=0;i<n;i++) swap(aa[i*2],aa[i*2+1]);
        }
        cur^=1;
        cnt++;
    }
    iota(tar.begin(),tar.end(),1);
    if(tar==aa)
    {
        suc=1;
        ans=cnt;
    }
    aa=a;
    cnt=0;
    cur=1;
    while(aa[0]!=1)
    {
        if(cur==0)
        {
            for(int i=0;i<n;i++) swap(aa[i],aa[i+n]);
        }
        else{
            for(int i=0;i<n;i++) swap(aa[i*2],aa[i*2+1]);
        }
        cur^=1;
        cnt++;
    }
    if(tar==aa)
    {
        ans=min(ans,cnt);
        suc=1;
    }
    if(!suc)
    {
        cout<<-1<<'\n';
        return 0;
    }
    cout<<ans<<'\n';

}