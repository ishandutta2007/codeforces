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
        int a,b,c;
        cin >> a >> b >> c;
        int x=(a-1);
        int y=abs(b-c)+c-1;
        int res=0;
        if(x<=y) res++;
        if(x>=y) res+=2;
        cout << res << "\n";
    }
    return 0;
}