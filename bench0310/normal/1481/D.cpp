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
        vector<string> s(n+1);
        for(int i=1;i<=n;i++)
        {
            cin >> s[i];
            s[i]="$"+s[i];
        }
        vector<int> res(m+1,0);
        bool ok=[&]()
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(s[i][j]==s[j][i]||(s[i][j]!=s[j][i]&&(m&1)))
                    {
                        for(int k=0;k<=m;k++) res[k]=((k%2)==0?i:j);
                        return 1;
                    }
                }
            }
            if(n==2) return 0;
            int a=0,b=0,c=0;
            array<int,3> v={1,2,3};
            do
            {
                auto [x,y,z]=v;
                if(s[x][y]==s[y][z])
                {
                    tie(a,b,c)={x,y,z};
                    break;
                }
            }while(next_permutation(v.begin(),v.end()));
            assert(a!=0);
            int now=a;
            if((m/2-1)&1) now=b;
            for(int i=0;i<=(m/2-1);i++)
            {
                res[i]=now;
                now^=(a^b);
            }
            assert(now==b);
            res[m/2]=b;
            res[m/2+1]=c;
            now=b;
            for(int i=m/2+2;i<=m;i++)
            {
                res[i]=now;
                now^=(b^c);
            }
            return 1;
        }();
        if(ok)
        {
            cout << "YES\n";
            for(int i=0;i<=m;i++) cout << res[i] << " \n"[i==m];
        }
        else cout << "NO\n";
    }
    return 0;
}