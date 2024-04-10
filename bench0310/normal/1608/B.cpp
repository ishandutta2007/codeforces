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
        int n,a,b;
        cin >> n >> a >> b;
        vector<int> p(n+1,0);
        bool ok=[&]()->bool
        {
            if(abs(a-b)>=2) return 0;
            if(a+b>n-2) return 0;
            int x=(a<b);
            int l=1,r=n;
            if(a==0&&b==0)
            {
                for(int i=1;i<=n;i++) p[i]=i;
                return 1;
            }
            int pos=2+a+b;
            for(int i=2;i<=n;i++)
            {
                if(x==0)
                {
                    if(a==0) break;
                    p[i]=(r--);
                    a--;
                }
                else
                {
                    if(b==0) break;
                    p[i]=(l++);
                    b--;
                }
                x^=1;
            }
            if(x==0)
            {
                for(int i=pos;i<=n;i++) p[i]=(l++);
                p[1]=(l++);
            }
            else
            {
                for(int i=pos;i<=n;i++) p[i]=(r--);
                p[1]=(r--);
            }
            return 1;
        }();
        if(ok)
        {
            for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
        }
        else cout << "-1\n";
    }
    return 0;
}