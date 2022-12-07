#include <bits/stdc++.h>
using namespace std;
const int sz=210;
int dp[sz][sz][sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int R, G, B, an=0;
    cin>>R>>G>>B;
    int wr[R], wg[G], wb[B];
    for(int a=0; a<R; a++) cin>>wr[a];
    sort(wr, wr+R);
    for(int a=0; a<G; a++) cin>>wg[a];
    sort(wg, wg+G);
    for(int a=0; a<B; a++) cin>>wb[a];
    sort(wb, wb+B);
    for(int rq=R; rq>=0; rq--)
    {
        for(int gq=G; gq>=0; gq--)
        {
            for(int bq=B; bq>=0; bq--)
            {
                an=max(an, dp[rq][gq][bq]);
                if(rq and gq) dp[rq-1][gq-1][bq]=max(dp[rq-1][gq-1][bq], dp[rq][gq][bq]+wr[rq-1]*wg[gq-1]);

                if(rq and bq) dp[rq-1][gq][bq-1]=max(dp[rq-1][gq][bq-1], dp[rq][gq][bq]+wr[rq-1]*wb[bq-1]);

                if(gq and bq) dp[rq][gq-1][bq-1]=max(dp[rq][gq-1][bq-1], dp[rq][gq][bq]+wg[gq-1]*wb[bq-1]);
            }
        }
    }
    cout<<an;
}