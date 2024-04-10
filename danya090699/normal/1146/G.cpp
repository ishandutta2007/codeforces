#include <bits/stdc++.h>
using namespace std;
const int sz=55;
int dp[sz][sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, h, m;
    cin>>n>>h>>m;
    int ar[m][3];
    vector <int> ot[h+1];
    for(int a=0; a<m; a++)
    {
        int ch;
        cin>>ar[a][0]>>ar[a][1]>>ch>>ar[a][2];
        ar[a][0]--, ar[a][1]--;
        ot[ch].push_back(a);
    }
    for(int a=1; a<=n; a++)
    {
        for(int l=0; l+a-1<n; l++)
        {
            int r=l+a-1;
            for(int c=l; c<=r; c++)
            {
                int add=0;
                for(int i=0; i<=h; i++)
                {
                    dp[a][l][i]=max(dp[a][l][i], add+i*i+dp[c-l][l][i]+dp[r-c][c+1][i]);
                    for(int b=0; b<ot[i].size(); b++)
                    {
                        int lg=ar[ot[i][b]][0], rg=ar[ot[i][b]][1], va=ar[ot[i][b]][2];
                        if(lg>=l and rg<=r and lg<=c and rg>=c) add-=va;
                    }
                }

            }
            for(int i=1; i<=h; i++) dp[a][l][i]=max(dp[a][l][i], dp[a][l][i-1]);
        }
    }
    cout<<dp[n][0][h];
}