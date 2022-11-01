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
        vector<array<int,5>> r(n);
        for(int i=0;i<n;i++) for(int j=0;j<5;j++) cin >> r[i][j];
        auto cmp=[&](int i,int j)
        {
            int c=0;
            for(int k=0;k<5;k++) c+=(r[i][k]>r[j][k]);
            return (c>=3);
        };
        int x=0;
        for(int i=1;i<n;i++) if(cmp(x,i)==1) x=i;
        bool ok=1;
        for(int i=0;i<n;i++) if(i!=x) ok&=(cmp(i,x)==1);
        if(ok) cout << x+1 << "\n";
        else cout << "-1\n";
    }
    return 0;
}