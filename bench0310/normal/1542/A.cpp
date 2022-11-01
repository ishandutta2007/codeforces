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
        for(int i=0;i<2*n;i++)
        {
            int a;
            cin >> a;
            c[a&1]++;
        }
        if(c[0]==c[1]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}