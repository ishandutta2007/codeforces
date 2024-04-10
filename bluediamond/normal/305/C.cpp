#include <bits/stdc++.h>

using namespace std;

int n;
map<int,int>cnt;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(auto itr:cnt)
    {
        int id=itr.first;
        int have=itr.second;
        if(have>=2)
        {
            cnt[id+1]+=have/2;
            cnt[id]%=2;
        }
    }
    int maxx=0,sz=0;
    for(auto itr:cnt)
    {
        maxx=max(maxx,itr.first);
        if(itr.second)
            sz++;
    }
    cout<<maxx-sz+1<<"\n";
   // cout<<sz<<" "<<maxx<<"\n";
    return 0;
}