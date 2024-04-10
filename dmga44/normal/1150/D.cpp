#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

int ant[MAXN][26];
vector<pii> qs;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i=0;i<26;i++)
        ant[n][i]=ant[n+1][i]=n;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<26;j++)
            ant[i][j]=ant[i+1][j];
        ant[i][s[i]-'a']=i;
    }

    int c[3],m[3];
    for(int i=0;i<3;i++)
        c[i]=m[i]=0;
    for(int i=0;i<q;i++)
    {
        char cc;
        int t;
        cin >> cc >> t;
        t--;
        if(cc=='-')
        {
            c[t]--;
            qs.push_back(pii(-(t+1),0));
        }
        else
        {
            cin >> cc;
            c[t]++;
            qs.push_back(pii(t+1,cc-'a'));
            m[t]=max(m[t],c[t]);
        }
    }

    for(int i=0;i<3;i++)
        m[i]++,c[i]=0;

    vector<vector<vector<int> > > dp;
    vector<vector<int> > dp1;
    vector<int> dp2(m[2]);
    for(int i=0;i<m[2];i++)
        dp2[i]=-1;
    for(int i=0;i<m[1];i++)
        dp1.push_back(dp2);
    for(int i=0;i<m[0];i++)
        dp.push_back(dp1);

    vector<int> v[3];
    for(auto y : qs)
    {
        int t=abs(y.first)-1;
        if(y.first<0)
        {
            c[t]--;
            v[t].pop_back();
            if(dp[c[0]][c[1]][c[2]]<n)
                db("YES")
            else
                db("NO")
        }
        else
        {
            int cc=y.second;
            c[t]++;
            v[t].push_back(cc);
            if(t==0)
            {
                for(int i=0;i<=c[1];i++)
                    for(int j=0;j<=c[2];j++)
                    {
                        dp[c[0]][i][j]=n;
                        if(c[0]>0)
                            dp[c[t]][i][j]=min(dp[c[t]][i][j],ant[dp[c[t]-1][i][j]+1][cc]);
                        if(i>0)
                            dp[c[t]][i][j]=min(dp[c[t]][i][j],ant[dp[c[t]][i-1][j]+1][v[1][i-1]]);
                        if(j>0)
                            dp[c[t]][i][j]=min(dp[c[t]][i][j],ant[dp[c[t]][i][j-1]+1][v[2][j-1]]);
                    }
            }
            else if(t==1)
            {
                for(int i=0;i<=c[0];i++)
                    for(int j=0;j<=c[2];j++)
                    {
                        dp[i][c[1]][j]=n;
                        if(c[1]>0)
                            dp[i][c[1]][j]=min(dp[i][c[1]][j],ant[dp[i][c[1]-1][j]+1][cc]);
                        if(i>0)
                            dp[i][c[1]][j]=min(dp[i][c[1]][j],ant[dp[i-1][c[1]][j]+1][v[0][i-1]]);
                        if(j>0)
                            dp[i][c[1]][j]=min(dp[i][c[1]][j],ant[dp[i][c[1]][j-1]+1][v[2][j-1]]);
                    }
            }
            else
            {
                for(int i=0;i<=c[0];i++)
                    for(int j=0;j<=c[1];j++)
                    {
                        dp[i][j][c[2]]=n;
                        if(c[2]>0)
                            dp[i][j][c[2]]=min(dp[i][j][c[2]],ant[dp[i][j][c[2]-1]+1][cc]);
                        if(i>0)
                            dp[i][j][c[2]]=min(dp[i][j][c[2]],ant[dp[i-1][j][c[2]]+1][v[0][i-1]]);
                        if(j>0)
                            dp[i][j][c[2]]=min(dp[i][j][c[2]],ant[dp[i][j-1][c[2]]+1][v[1][j-1]]);
                    }
            }
            if(dp[c[0]][c[1]][c[2]]<n)
                db("YES")
            else
                db("NO")
        }
    }

    return 0;
}