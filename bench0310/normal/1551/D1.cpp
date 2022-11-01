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
        int n,m,k;
        cin >> n >> m >> k;
        vector<string> res(n,string(m,'0'));
        auto in=[&](int i,int j)->bool{return (0<=i&&i<n&&0<=j&&j<m);};
        auto place=[&](int r,int c,int tp)
        {
            int r2=r+(tp==1);
            int c2=c+(tp==0);
            assert(res[r][c]=='0'&&res[r2][c2]=='0');
            for(char a='a';a<='z';a++)
            {
                bool ok=1;
                for(int i=r-1;i<=r+2;i++)
                {
                    for(int j=c-1;j<=c+2;j++)
                    {
                        if(!in(i,j)) continue;
                        if((abs(i-r)+abs(j-c))!=1&&(abs(i-r2)+abs(j-c2))!=1) continue;
                        if(res[i][j]==a) ok=0;
                    }
                }
                if(ok)
                {
                    res[r][c]=res[r2][c2]=a;
                    break;
                }
            }
        };
        if(n&1)
        {
            for(int j=0;j+1<m;j+=2)
            {
                if(k==0) break;
                place(0,j,0);
                k--;
            }
        }
        for(int i=(n&1);i+1<n;i+=2)
        {
            for(int j=0;j+1<m;j+=2)
            {
                if(k<2) break;
                place(i,j,0);
                place(i+1,j,0);
                k-=2;
            }
        }
        for(int i=0;i+1<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(res[i][j]=='0'&&res[i+1][j]=='0') place(i,j,1);
            }
        }
        bool ok=(k==0);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) ok&=(res[i][j]!='0');
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}