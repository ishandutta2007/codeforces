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
        int n;
        cin >> n;
        vector<int> c(101,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            c[a]++;
        }
        int res=0;
        for(int i=0;i<=100;i++)
        {
            if(c[i]<2)
            {
                res+=i;
                break;
            }
        }
        for(int i=0;i<=100;i++)
        {
            if(c[i]==0)
            {
                res+=i;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}