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
        if(n==1) n=4;
        int res=0;
        while((n%3)!=0)
        {
            res++;
            n-=2;
        }
        cout << res+(n/3) << "\n";
    }
    return 0;
}