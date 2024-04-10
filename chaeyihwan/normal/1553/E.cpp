#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int p[300002], cnt[300002];
int t[300002];
bool visited[300002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        int inv = 0;
        for(int i=1;i<=n;i++)
        {
            cin >> p[i];
            int tmp = (i - p[i] + n)%n;
            cnt[tmp]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(cnt[i] < n/3) continue;
            for(int j=1;j<=n;j++)
            {
                t[j] = (p[j] + i)%n;
                if(t[j] == 0) t[j] = n;
                visited[j] = 0;
            }

            int cnt = 0;
            for(int j=1;j<=n;j++)
            {
                if(!visited[j])
                {
                    cnt++;
                    visited[j] = true;
                    int k = t[j];
                    while(k != j)
                    {
                        visited[k] = true;
                        k = t[k];
                    }
                }
            }

            if(m >= n - cnt) q.push(i);
        }

        cout << q.size() << " ";
        while(!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }
}