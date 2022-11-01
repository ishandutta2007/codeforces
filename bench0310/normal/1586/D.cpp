#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto q=[&](int p,int a)->int
    {
        cout << "? ";
        for(int i=1;i<=n;i++) cout << (i==p?a:(a^3)) << " \n"[i==n];
        cout.flush();
        int r;
        cin >> r;
        return r;
    };
    vector<int> v[n+1];
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int x=q(i,2);
        if(x!=0&&i!=x)
        {
            v[i].push_back(x);
            v[x].push_back(i);
        }
        int y=q(i,1);
        if(y==0) s=i;
        else if(i!=y)
        {
            v[i].push_back(y);
            v[y].push_back(i);
        }
    }
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++)
    {
        p[s]=i;
        int ns=v[s][0];
        if(p[ns]!=0) ns=v[s][1];
        s=ns;
    }
    cout << "! ";
    for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
    cout.flush();
    return 0;
}