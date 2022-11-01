#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> vr[n+1];
    vector<int> out(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        vr[b].push_back(a);
        out[a]++;
    }
    priority_queue<int> q;
    for(int i=1;i<=n;i++) if(out[i]==0) q.push(i);
    vector<int> res(n+1,0);
    int now=n;
    while(!q.empty())
    {
        int a=q.top();
        q.pop();
        res[a]=now--;
        for(int from:vr[a]) if((--out[from])==0) q.push(from);
    }
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}