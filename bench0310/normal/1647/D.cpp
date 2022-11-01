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
        auto bad=[&](int a)->bool
        {
            for(int i=2;i*i<=a;i++) if((a%i)==0) return 0;
            return 1;
        };
        int x,d;
        cin >> x >> d;
        bool res=[&]()->bool
        {
            if((x%(ll(d)*d))!=0) return 0;
            int k=0;
            int r=x;
            while((r%d)==0)
            {
                r/=d;
                k++;
            }
            if(!bad(r)) return 1;
            if(k==3)
            {
                int y=r*d;
                for(int i=1;i*i<=y;i++)
                {
                    if((y%i)!=0) continue;
                    if((i%d)!=0&&((y/i)%d)!=0) return 1;
                }
            }
            if(k>=4&&!bad(d)) return 1;
            return 0;
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}