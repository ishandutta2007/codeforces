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
        int s;
        cin >> s;
        int res=0;
        for(int i=1;s>0;i+=2)
        {
            s-=i;
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}