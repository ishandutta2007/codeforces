#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10, inf=1e9;
bool us[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    string fi[n];
    for(int a=0; a<n; a++) cin>>fi[a];
    int dp[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) dp[a][b]=inf;
    dp[0][0]=1;
    if(fi[0][0]=='a') dp[0][0]=0;
    for(int a=0; a<2*n-1; a++)
    {
        for(int x=0; x<n; x++)
        {
            int y=a-x;
            if(y>=0 and y<n)
            {
                if(x+1<n) dp[x+1][y]=min(dp[x+1][y], dp[x][y]+1-(fi[x+1][y]=='a'));
                if(y+1<n) dp[x][y+1]=min(dp[x][y+1], dp[x][y]+1-(fi[x][y+1]=='a'));

                //cout<<dp[x][y]<<" ";
            }
        }
        //cout<<"\n";
    }
    queue <pair <int, int> > qu;
    string an;
    for(int a=2*n-2; a>=0; a--)
    {
        for(int x=0; x<n; x++)
        {
            int y=a-x;
            if(y>=0 and y<n)
            {
                if(dp[x][y]<=k) qu.push({x, y});
            }
        }
        if(qu.size())
        {
            for(int b=0; b<=a; b++) an.push_back('a');
            break;
        }
    }
    //cout<<dp[2][0]<<"\n";
    if(qu.size()==0) qu.push({0, -1});

    while(qu.size())
    {
        int q=qu.size();
        char be='z';
        vector <pair <int, int> > sp;
        for(int a=0; a<q; a++)
        {
            int x=qu.front().first, y=qu.front().second;
            //cout<<x<<" "<<y<<"\n";
            if(x+1<n and y>=0) be=min(be, fi[x+1][y]);
            if(x>=0 and y+1<n) be=min(be, fi[x][y+1]);
            sp.push_back(qu.front());
            qu.pop();
        }
        //cout<<"\n\n";
        for(int a=0; a<sp.size(); a++)
        {
            int x=sp[a].first, y=sp[a].second;
            if(x+1<n and y>=0)
            {
                if(fi[x+1][y]==be and us[x+1][y]==0)
                {
                    us[x+1][y]=1, qu.push({x+1, y});
                }
            }
            if(x>=0 and y+1<n)
            {
                if(fi[x][y+1]==be and us[x][y+1]==0)
                {
                    us[x][y+1]=1, qu.push({x, y+1});
                }
            }
        }
        if(qu.size()) an.push_back(be);
    }
    cout<<an;
}