#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=1000;
    int n,k;
    cin >> n >> k;
    vector<bool> a(N+1,0);
    while(k--)
    {
        int b;
        cin >> b;
        a[b]=1;
    }
    vector<int> v;
    for(int i=0;i<=N;i++) if(a[i]) v.push_back(i-n);
    vector<int> d(2*N+1,-1);
    queue<int> q;
    for(int x:v)
    {
        d[x+N]=1;
        q.push(x);
    }
    while(!q.empty())
    {
        int e=q.front();
        q.pop();
        for(int x:v)
        {
            if(-N<=x+e&&x+e<=N&&d[x+e+N]==-1)
            {
                d[x+e+N]=d[e+N]+1;
                q.push(x+e);
            }
        }
    }
    cout << d[N] << "\n";
    return 0;
}