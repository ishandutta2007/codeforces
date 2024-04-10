#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int mod=32768;
    vector<int> v[mod];
    for(int i=0;i<mod;i++)
    {
        v[(i+1)%mod].push_back(i);
        v[(2*i)%mod].push_back(i);
    }
    queue<int> q;
    q.push(0);
    vector<int> d(mod,-1);
    d[0]=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a])
        {
            if(d[to]==-1)
            {
                d[to]=d[a]+1;
                q.push(to);
            }
        }
    }
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        cout << d[a] << " \n"[i==n];
    }
    return 0;
}