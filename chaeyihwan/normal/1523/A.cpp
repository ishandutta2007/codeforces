#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9+7;

int dist[1002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i=0;i<n;i++) dist[i] = INF;
        string s; cin >> s;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
            {
                dist[i] = 0;
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int now = q.front(); q.pop();
            if(now > 0 && dist[now-1] > dist[now] + 1)
            {
                dist[now-1] = dist[now] + 1;
                q.push(now-1);
            }
            if(now < n-1 && dist[now+1] > dist[now] + 1)
            {
                dist[now+1] = dist[now] + 1;
                q.push(now+1);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(dist[i] == 0) cout << "1";
            else if(dist[i] > m) cout << "0";
            else if(i>0 && i<n-1 && dist[i-1] == dist[i+1]) cout << "0";
            else cout << "1";
        }

        cout << "\n";
    }
}