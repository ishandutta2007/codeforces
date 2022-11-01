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
        int x,y;
        cin >> x >> y;
        cout << [&]()->int
        {
            if(x==0&&y==0) return 0;
            int z=(x*x+y*y);
            for(int i=1;i*i<=z;i++) if(i*i==z) return 1;
            return 2;
        }() << "\n";
    }
    return 0;
}