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
        vector<array<int,2>> c(n+1,{0,0});
        auto chmax=[&](int &a,int b){a=max(a,b);};
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            chmax(c[a][i&1],c[a][1-(i&1)]+1);
        }
        for(int i=1;i<=n;i++) cout << max(c[i][0],c[i][1]) << " \n"[i==n];
    }
    return 0;
}