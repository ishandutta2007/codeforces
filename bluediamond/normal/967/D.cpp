#include <bits/stdc++.h>

using namespace std;

struct info
{
    int x,i;
};
bool cmp(info a,info b)
{
    return a.x>b.x;
}
const int N=300000;
int n,s[5];
info v[N+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s[1]>>s[2];
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].x;
        v[i].i=i;
    }
    sort(v+1,v+n+1,cmp);
    for(int nr=1;nr<=2;nr++)
    {
        int gasit=-1;
        for(int i=1;i<=n;i++)
            if((long long)i*v[i].x>=s[nr])
            {
                gasit=i;
                break;
            }
        if(gasit==-1)continue;
        int gasit2=-1;
        for(int i=gasit+1;i<=n;i++)
            if((long long)(i-gasit)*v[i].x>=s[3-nr])
            {
                gasit2=i;
                break;
            }
        if(gasit2==-1)continue;
        cout<<"Yes\n";
        if(nr==2)
        {
            cout<<gasit2-gasit<<" "<<gasit<<"\n";
            for(int i=gasit+1;i<=gasit2;i++)
                cout<<v[i].i<<" ";
            cout<<"\n";
            for(int i=1;i<=gasit;i++)
                cout<<v[i].i<<" ";
            return 0;
        }
        cout<<gasit<<" "<<gasit2-gasit<<"\n";
        for(int i=1;i<=gasit;i++)
            cout<<v[i].i<<" ";
        cout<<"\n";
        for(int i=gasit+1;i<=gasit2;i++)
            cout<<v[i].i<<" ";
        return 0;
    }
    cout<<"No";
    return 0;
}