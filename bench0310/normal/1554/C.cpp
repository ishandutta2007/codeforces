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
        int n,m;
        cin >> n >> m;
        bool b=0;
        int p=30;
        int res=0;
        for(int i=29;i>=0;i--)
        {
            int x=(n>>i)&1;
            int y=(m>>i)&1;
            if(x==0&&y==1) res^=(1<<i);
            if(x==0&&y==0) p=i;
            if(x==1&&y==0)
            {
                b=1;
                break;
            }
        }
        if(!b)
        {
            res^=(1<<p);
            for(int i=0;i<p;i++) if(res&(1<<i)) res^=(1<<i);
        }
        cout << res << "\n";
    }
    return 0;
}