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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) a[i]=i;
        vector<array<int,2>> res;
        auto op=[&](int x,int y)
        {
            res.push_back({x,y});
            a[x]=(a[x]+a[y]-1)/a[y];
//            cout << "[" << x << "," << y << "]" << endl;
//            for(int i=1;i<=n;i++) cout << a[i] << " ";
//            cout << endl;
        };
        for(int i=1;i<n;i++) if(__builtin_popcount(i)>1) op(i,n);
        int b=0;
        while((1<<(b+1))<n) b++;
        op(n,(1<<b));
        int pos=(1<<b);
        int now=b-1;
        while(b>=2)
        {
            while(now>b/2) op((1<<(now--)),pos);
            op(pos,(1<<(b/2)));
            b-=(b/2);
        }
        vector<int> two;
        for(int i=1;i<=n;i++)
        {
            assert(a[i]<=2);
            if(a[i]==2) two.push_back(i);
        }
        for(int i=0;i<(int)two.size()-1;i++) op(two[i],two[i+1]);
        cout << res.size() << "\n";
        for(auto [x,y]:res) cout << x << " " << y << "\n";
    }
    return 0;
}