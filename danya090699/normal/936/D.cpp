#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, inf=1e9+10;
int dp[2][sz], pos[sz];
bool us[2][sz], pr[2][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m1, m2, t;
    cin>>n>>m1>>m2>>t;
    int p1[m1], p2[m2];
    for(int a=0; a<m1; a++) scanf("%d", &p1[a]);
    for(int a=0; a<m2; a++) scanf("%d", &p2[a]);
    int yk1=0, yk2=0, q=1;
    dp[0][0]=0, dp[1][0]=-inf, pos[0]=0;
    while(yk1<m1 or yk2<m2)
    {
        pos[q]=inf;
        if(yk1<m1) pos[q]=min(pos[q], p1[yk1]);
        if(yk2<m2) pos[q]=min(pos[q], p2[yk2]);
        if(yk1<m1)
        {
            if(p1[yk1]==pos[q])
            {
                us[0][q]=1, yk1++;
            }
        }
        if(yk2<m2)
        {
            if(p2[yk2]==pos[q])
            {
                us[1][q]=1, yk2++;
            }
        }
        dp[0][q]=-inf, dp[1][q]=-inf;
        for(int b=0; b<2; b++)
        {
            if(dp[b][q-1]!=-inf)
            {
                int d=dp[b][q-1]+(pos[q]-pos[q-1]);
                if(us[b][q])
                {
                    if(d>t and dp[b][q]<d-t)
                    {
                        dp[b][q]=d-t, pr[b][q]=0;
                    }
                }
                else if(dp[b][q]<d)
                {
                    dp[b][q]=d, pr[b][q]=0;
                }
                if(us[b^1][q-1]==0 or (pos[q]-pos[q-1])>1)
                {
                    d=min(dp[b][q-1], t)+(pos[q]-pos[q-1]);
                    if(us[b^1][q-1]) d=min(dp[b][q-1]+1, t)+(pos[q]-pos[q-1]-1);
                    if(us[b^1][q])
                    {
                        if(d>t and dp[b^1][q]<d-t)
                        {
                            dp[b^1][q]=d-t, pr[b^1][q]=1;
                        }
                    }
                    else if(dp[b^1][q]<d)
                    {
                        dp[b^1][q]=d, pr[b^1][q]=1;
                    }
                }
            }
        }
        q++;
    }
    if(dp[0][q-1]!=-inf or dp[1][q-1]!=-inf)
    {
        cout<<"Yes\n";
        int cu=0;
        if(dp[0][q-1]==-inf) cu=1;
        vector <int> go;
        vector <pair <int, int> > sh;
        for(int a=q-1; a>0; a--)
        {
            if(us[cu][a]) sh.push_back(make_pair(pos[a]-dp[cu][a], cu+1));
            if(pr[cu][a])
            {
                if(us[cu][a-1]) go.push_back(pos[a-1]+1);
                else go.push_back(pos[a-1]);
                cu^=1;
            }
        }
        reverse(go.begin(), go.end());
        reverse(sh.begin(), sh.end());
        cout<<go.size()<<"\n";
        for(int a=0; a<go.size(); a++) printf("%d ", go[a]);
        cout<<"\n"<<sh.size()<<"\n";
        for(int a=0; a<sh.size(); a++) printf("%d %d\n", sh[a].first, sh[a].second);
    }
    else cout<<"No";
}