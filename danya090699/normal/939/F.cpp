#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, pr=0;
    cin>>n>>k;
    int dp[2][n*2+1], dp2[2][n*2+1], add[2][n*2+1];
    for(int a=0; a<=n*2; a++)
    {
        for(int b=0; b<2; b++)
        {
            dp[b][a]=inf, dp2[b][a]=inf, add[b][a]=inf;
        }
    }
    dp[0][0]=0;
    for(int a=0; a<k; a++)
    {
        int l, r;
        cin>>l>>r;
        int d=r-l;
        for(int b=0; b<=n*2; b++)
        {
            for(int c=0; c<2; c++)
            {
                if(dp[c][b]!=inf)
                {
                    int q1=b+(l-pr), q2=pr-b;
                    dp2[c][b+(r-pr)]=dp[c][b];
                    add[c^1][q2]=min(add[c^1][q2], dp[c][b]+1);
                    add[c][q1]=min(add[c][q1], dp[c][b]+2);
                }
            }
        }
        for(int b=0; b<2; b++)
        {
            deque <pair <int, int> > st;
            for(int c=0; c<=n*2; c++)
            {
                if(add[b][c]!=inf)
                {
                    while(st.size())
                    {
                        if(st.back().first>add[b][c]) st.pop_back();
                        else break;
                    }
                    st.push_back(make_pair(add[b][c], c+d+1));
                }
                if(st.size())
                {
                    if(st.front().second==c) st.pop_front();
                }
                if(st.size())
                {
                    dp2[b][c]=min(dp2[b][c], st.front().first);
                }
            }
        }
        for(int b=0; b<2; b++)
        {
            for(int c=0; c<=n*2; c++)
            {
                dp[b][c]=dp2[b][c], dp2[b][c]=inf, add[b][c]=inf;
            }
        }
        pr=r;
    }
    for(int a=0; a<2; a++)
    {
        for(int b=0; b<=n*2; b++) if(dp[a][b]!=inf) dp2[a][b+(n*2-pr)]=dp[a][b];
    }
    int an=min(dp2[0][n], dp2[1][n]);
    if(an==inf) cout<<"Hungry";
    else cout<<"Full\n"<<an;
}