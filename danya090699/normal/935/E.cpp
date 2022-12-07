#include <bits/stdc++.h>
using namespace std;
const int sz=1e4+10, sz2=110, inf=1e9;
int mi[sz][sz2], ma[sz][sz2], pq, mq, q=1;
string s;
void dfs(int nu, int l, int r)
{
    if(l==r)
    {
        mi[nu][0]=s[l]-'0';
        ma[nu][0]=s[l]-'0';
    }
    else
    {
        int le=0;
        for(int a=l; ; a++)
        {
            if(s[a]=='(') le++;
            if(s[a]==')') le--;
            if(s[a]=='?' and le==1)
            {
                int ln, rn;
                ln=q, q++, dfs(q-1, l+1, a-1);
                rn=q, q++, dfs(q-1, a+1, r-1);
                for(int b=0; b<=min(pq, mq); b++)
                {
                    for(int c=0; c<=b; c++)
                    {
                        if(pq<=mq)
                        {
                            mi[nu][b]=min(mi[nu][b], mi[ln][c]-ma[rn][b-c]);
                            if(c<b) mi[nu][b]=min(mi[nu][b], mi[ln][c]+mi[rn][b-c-1]);
                            ma[nu][b]=max(ma[nu][b], ma[ln][c]-mi[rn][b-c]);
                            if(c<b) ma[nu][b]=max(ma[nu][b], ma[ln][c]+ma[rn][b-c-1]);
                        }
                        else
                        {
                            if(c<b) mi[nu][b]=min(mi[nu][b], mi[ln][c]-ma[rn][b-c-1]);
                            mi[nu][b]=min(mi[nu][b], mi[ln][c]+mi[rn][b-c]);
                            if(c<b) ma[nu][b]=max(ma[nu][b], ma[ln][c]-mi[rn][b-c-1]);
                            ma[nu][b]=max(ma[nu][b], ma[ln][c]+ma[rn][b-c]);
                        }
                    }
                }
                break;
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>s>>pq>>mq;
    for(int a=0; a<sz; a++)
    {
        for(int b=0; b<=min(pq, mq); b++)
        {
            mi[a][b]=inf, ma[a][b]=-inf;
        }
    }
    dfs(0, 0, s.size()-1);
    cout<<ma[0][min(pq, mq)];
}