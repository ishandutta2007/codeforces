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
        array<int,2> c={0,0};
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            c[a]++;
        }
        if(c[0]>=c[1])
        {
            cout << c[0] << "\n";
            for(int i=1;i<=c[0];i++) cout << "0" << " \n"[i==c[0]];
        }
        else
        {
            if(c[1]&1) c[1]--;
            cout << c[1] << "\n";
            for(int i=1;i<=c[1];i++) cout << "1" << " \n"[i==c[1]];
        }
    }
    return 0;
}