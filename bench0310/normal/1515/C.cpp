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
        int n,m,x;
        cin >> n >> m >> x;
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
        for(int i=1;i<=m;i++) q.push({0,i});
        cout << "YES\n";
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            auto [h,j]=q.top();
            q.pop();
            cout << j << " \n"[i==n];
            q.push({h+a,j});
        }
    }
    return 0;
}