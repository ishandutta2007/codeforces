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
        vector<vector<int>> a(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> a[i][j];
        string ops;
        cin >> ops;
        array<int,3> now={0,1,2};
        array<int,3> d={0,0,0};
        for(char c:ops)
        {
            if(c=='L') d[now[1]]--;
            else if(c=='R') d[now[1]]++;
            else if(c=='U') d[now[0]]--;
            else if(c=='D') d[now[0]]++;
            else if(c=='I') swap(now[1],now[2]);
            else if(c=='C') swap(now[0],now[2]);
        }
        vector<vector<int>> b(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                array<int,3> x={i,j,a[i][j]};
                for(int k=0;k<3;k++)
                {
                    x[k]=(((x[k]+d[k])%n)+n)%n;
                    if(x[k]==0) x[k]=n;
                }
                array<int,3> y={0,0,0};
                for(int k=0;k<3;k++) y[k]=x[now[k]];
                b[y[0]][y[1]]=y[2];
            }
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout << b[i][j] << " \n"[j==n];
    }
    return 0;
}