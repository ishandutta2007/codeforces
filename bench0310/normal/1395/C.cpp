#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> one(n,0);
    for(int i=0;i<n;i++) cin >> one[i];
    vector<int> two(m,0);
    for(int i=0;i<m;i++) cin >> two[i];
    for(int x=0;x<(1<<9);x++)
    {
        bool ok=1;
        for(int a:one)
        {
            bool f=0;
            for(int b:two) if(((a&b)&(~x))==0) f=1;
            ok&=f;
        }
        if(ok==1)
        {
            cout << x << "\n";
            break;
        }
    }
    return 0;
}