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
        int n,r,b;
        cin >> n >> r >> b;
        int c=(r/(b+1));
        int d=(r%(b+1));
        for(int i=1;i<=b+1;i++)
        {
            int x=c+(d>0);
            d--;
            cout << string(x,'R');
            if(i<=b) cout << "B";
        }
        cout << "\n";
    }
    return 0;
}