#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int w[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        for(int i=1;i<=n;i++) cin >> w[i];

        sort(w + 1, w + n + 1);

        int sum = 0;
        bool flag = false;
        for(int i=1;i<=n;i++)
        {
            sum += w[i];
            if(sum == x)
            {
                flag = true;
                if(i == n)
                {
                    cout << "NO\n";
                    continue;
                }

                else
                {
                    swap(w[i], w[i+1]);
                    cout << "YES\n";
                    for(int j=1;j<=n;j++)
                    {
                        cout << w[j] << " ";
                    }
                    cout << "\n";
                    continue;
                }
            }
        }
        if(!flag)
        {
            cout << "YES\n";
            for(int j=1;j<=n;j++)
            {
                cout << w[j] << " ";
            }
            cout << "\n";
        }
    }
}