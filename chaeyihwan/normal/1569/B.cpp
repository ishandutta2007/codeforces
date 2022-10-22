#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char ans[50][50];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0;
        for(int i=0;i<n;i++) if(s[i] == '2') cnt++;
        if(cnt == 1 || cnt == 2)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) ans[i][j] = (i == j ? 'X' : '=');
        }
        if(cnt > 1)
        {
            int S = 0;
            for(int i=0;i<n;i++)
            {
                if(s[i] == '2') {S = i; break; }
            }
            int now = S;
            for(int i=S+1;i<n;i++)
            {
                if(s[i] == '2')
                {
                    ans[i][now] = '+';
                    ans[now][i] = '-';
                    now = i;
                }
            }
            ans[S][now] = '+';
            ans[now][S] = '-';
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cout << ans[i][j];
            cout << "\n";
        }
    }
}