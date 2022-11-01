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
        int m=n;
        vector<vector<int>> v(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<m;j++) v[i][j+1]=(s[j]-'0');
        }
        for(int d=0;d<=9;d++)
        {
            int res=0;
            int mr1=-1,mr2=-1;
            int mc1=-1,mc2=-1;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(v[i][j]!=d) continue;
                    if(mr1==-1||i<mr1) mr1=i;
                    if(mr2==-1||i>mr2) mr2=i;
                    if(mc1==-1||j<mc1) mc1=j;
                    if(mc2==-1||j>mc2) mc2=j;
                }
            }
            if(mr1==-1)
            {
                cout << "0" << " \n"[d==9];
                continue;
            }
            for(int i=1;i<=n;i++)
            {
                int c1=-1,c2=-1;
                for(int j=1;j<=m;j++)
                {
                    if(v[i][j]!=d) continue;
                    if(c1==-1) c1=j;
                    c2=j;
                }
                if(c1==-1) continue;
                //don't use here
                res=max(res,(c2-c1)*max(i-1,n-i));
                //use here
                res=max(res,max(c2-1,m-c1)*max(i-mr1,mr2-i));
            }
            for(int j=1;j<=m;j++)
            {
                int r1=-1,r2=-1;
                for(int i=1;i<=n;i++)
                {
                    if(v[i][j]!=d) continue;
                    if(r1==-1) r1=i;
                    r2=i;
                }
                if(r1==-1) continue;
                //don't use here
                res=max(res,(r2-r1)*max(j-1,m-j));
                //use here
                res=max(res,max(r2-1,n-r1)*max(j-mc1,mc2-j));
            }
            cout << res << " \n"[d==9];
        }
    }
    return 0;
}