#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[100002][2];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=100000;i++) cnt[i][0] = cnt[i][1] = 0;
        for(int i=1;i<=n;i++)
        {
            int a; cin >> a;
            if(i%2) cnt[a][0]++;
            else cnt[a][1]++;
        }

        int now = 1, k = 0, c = 0;

        while(now <= 100000)
        {
            while(now <= 100000 && !cnt[now][k])
            {
                now++;
            }

            if(now > 100000) break;
            cnt[now][k]--; c++;
            //cout << now << "\n";
            k = 1 - k;
        }

        //cout << c << " ";

        if(c == n) cout << "YES\n";
        else cout << "NO\n";
    }
}