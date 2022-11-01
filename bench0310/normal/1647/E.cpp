#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,30>> p(n+1);
    vector<int> in(n+1,0);
    for(int i=1;i<=n;i++)
    {
        p[i].fill(0);
        cin >> p[i][0];
        in[p[i][0]]++;
    }
    for(int j=1;j<30;j++) for(int i=1;i<=n;i++) p[i][j]=p[p[i][j-1]][j-1];
    vector<int> a(n+1,0);
    int mx=0;
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        mx=max(mx,a[i]);
        if(a[i]<=n) s.erase(a[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=(in[i]==0);
    int t=((mx-n)/cnt);
    vector<bool> vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int q=i;
        for(int j=0;j<30;j++) if(t&(1<<j)) q=p[q][j];
        int b=0;
        if(!vis[a[q]])
        {
            b=a[q];
            vis[a[q]]=1;
        }
        else
        {
            auto it=s.lower_bound(a[q]);
            b=(*it);
            s.erase(it);
        }
        cout << b << " \n"[i==n];
    }
    return 0;
}