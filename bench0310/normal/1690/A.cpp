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
        int x=2,y=n-3,z=1;
        while(1)
        {
            if(x+1<y-1)
            {
                x++;
                y--;
            }
            else break;
            if(x<y-1&&z+1<x)
            {
                y--;
                z++;
            }
            else break;
        }
        cout << x << " " << y << " " << z << "\n";
    }
    return 0;
}