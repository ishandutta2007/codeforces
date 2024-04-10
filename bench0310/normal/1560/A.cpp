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
        int k;
        cin >> k;
        for(int i=1;;i++)
        {
            if((i%3)==0||(i%10)==3) continue;
            if((--k)==0)
            {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}