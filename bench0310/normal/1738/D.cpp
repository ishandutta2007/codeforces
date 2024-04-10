#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> b(n+1,0);
        vector<int> v[n+2];
        for(int i=1;i<=n;i++)
        {
            cin >> b[i];
            v[b[i]].push_back(i);
        }
        int s=1;
        int x=0;
        if(!v[n+1].empty())
        {
            s=0;
            x=n+1;
        }
        vector<int> a(n+1,0);
        int p=1;
        int l=0,r=n;
        while(p<=n)
        {
            int e=0;
            for(int i:v[x]) if(!v[i].empty()) e=i;
            for(int i:v[x]) if(i!=e) a[p++]=i;
            if(e!=0) a[p++]=e;
            if(s==0) l=max(l,v[x].back());
            else r=min(r,v[x][0]-1);
            x=e;
            s^=1;
        }
        cout << l << "\n";
        for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    }
    return 0;
}