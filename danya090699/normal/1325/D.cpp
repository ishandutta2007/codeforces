#include <bits/stdc++.h>
#define int long long
using namespace std;
int q[60];
main()
{
    //freopen("input.txt", "r", stdin);
    int u, v;
    cin>>u>>v;
    if(u>v)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0; i<60; i++) if(u&(1ll<<i)) q[i]++;
    v-=u;
    for(int i=0; i<60; i++) if(v&(1ll<<i)) q[i]++;
    for(int i=59; i>=0; i--)
    {
        int must=0;
        if(u&(1ll<<i)) must=1;
        if(q[i]%2!=must)
        {
            q[i]--;
            if(i) q[i-1]+=2;
            else
            {
                cout<<-1;
                return 0;
            }
        }
    }
    //cout<<q[1]<<" "<<q[0]<<"\n";
    int n=0;
    for(int i=0; i<60; i++) n=max(n, q[i]);
    int an[n];
    for(int a=0; a<n; a++) an[a]=0;
    for(int i=0; i<60; i++)
    {
        for(int a=0; a<q[i]; a++) an[a]+=(1ll<<i);
    }
    cout<<n<<"\n";
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}