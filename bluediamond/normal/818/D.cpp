#include <bits/stdc++.h>

using namespace std;

const int N=1000000+5;

int n,a;
int v[N];
vector<int>id[N];

int p[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>a;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        id[v[i]].push_back(i);
        p[i]=p[i-1]+(v[i]==a);
    }
    for(int x=1;x<N;x++)
    {
        if(x==a) continue;
        bool ok=1;
        int cnt=0;
        for(auto &i:id[x])
        {
            if(cnt<p[i])
            {
                ok=0;
                break;
            }
            cnt++;
        }
        if(cnt<p[n])
        {
            ok=0;
        }
        if(ok)
        {
            cout<<x<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}