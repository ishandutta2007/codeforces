#include <bits/stdc++.h>
using namespace std;
const int sz=100, inf=1e9+10;
int n, k, an=inf;
vector <int> sp;
pair <int, int> be[sz][sz][sz];
bool us[sz];
void dfs()
{
    if(sp.size()<k and sp.size()+1<n)
    {
        for(int a=sp.back()+1; a<n; a++)
        {
            sp.push_back(a), us[a]=1;
            dfs();
            sp.pop_back(), us[a]=0;
        }
    }
    int m=sp.size();
    int sm[m][m];
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<m; b++)
        {
            for(int c=0; ; c++)
            {
                if(!us[be[sp[a]][sp[b]][c].second])
                {
                    sm[a][b]=be[sp[a]][sp[b]][c].first;
                    break;
                }
            }
        }
    }
    int dp[k+1][m];
    for(int a=0; a<=k; a++) for(int b=0; b<m; b++) dp[a][b]=inf;
    dp[0][0]=0;
    for(int a=0; a<k; a++)
    {
        for(int b=0; b<m; b++)
        {
            for(int c=0; c<m; c++) dp[a+1][c]=min(dp[a+1][c], dp[a][b]+sm[b][c]);
        }
    }
    an=min(an, dp[k][0]);
}
main()
{
	//freopen("input.txt", "r", stdin);
    cin>>n>>k;
    k/=2;
    int sm[n][n];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++) scanf("%d", &sm[a][b]);
    }
    for(int a=0; a<n; a++) sm[a][a]=inf;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            for(int c=0; c<n; c++) be[a][b][c]={sm[a][c]+sm[c][b], c};
            sort(be[a][b], be[a][b]+n);
        }
    }
    sp.push_back(0), us[0]=1;
    dfs();
    cout<<an;
}