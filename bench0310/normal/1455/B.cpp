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
        for(int i=1;;i++)
        {
            int a=(i*(i+1)/2);
            if(a>=n&&(a-n)!=1)
            {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}