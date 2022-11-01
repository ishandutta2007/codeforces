#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    int r=0,c=0;
    int res=(s[0][0]=='*');
    while(1)
    {
        array<int,3> best={13,0,0};
        for(int i=r;i<n;i++)
        {
            for(int j=c;j<m;j++)
            {
                if(i==r&&j==c) continue;
                if(s[i][j]=='*') best=min(best,{i-r+j-c,i,j});
            }
        }
        if(best[0]!=13)
        {
            res++;
            r=best[1];
            c=best[2];
        }
        else break;
    }
    cout << res << "\n";
    return 0;
}