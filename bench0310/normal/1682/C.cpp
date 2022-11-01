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
        map<int,int> m;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            m[a]++;
        }
        int one=0,two=0;
        for(auto [a,c]:m)
        {
            if(c==1) one++;
            else two++;
        }
        if(one>=1) one++;
        cout << (one+2*two)/2 << "\n";
    }
    return 0;
}