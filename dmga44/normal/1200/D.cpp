#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 2005

int m[MAXN][MAXN],abi[MAXN],lims[2][MAXN][2];
string s[MAXN];
map<int,int> ma[MAXN];

int query(int p)
{
    int res=0;
    while(p)
    {
        res+=abi[p];
        p-=(p&-p);
    }
    return res;
}

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> s[i];

    int b=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(s[i][j]=='B')
            {
                lims[0][i][0]=j+1;
                break;
            }

        for(int j=n-1;j>=0;j--)
            if(s[i][j]=='B')
            {
                lims[0][i][1]=j+1;
                break;
            }

        if(!lims[0][i][0])
            b++;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(s[j][i]=='B')
            {
                lims[1][i][0]=j+1;
                break;
            }

        for(int j=n-1;j>=0;j--)
            if(s[j][i]=='B')
            {
                lims[1][i][1]=j+1;
                break;
            }

        if(!lims[1][i][0])
            b++;
    }

    for(int i=0;i<k-1;i++)
        if(lims[0][i][0])
            ma[lims[0][i][1]][lims[0][i][0]]++;

    for(int i=0;i+k<=n;i++)
    {
        if(lims[0][i+k-1][0])
            ma[lims[0][i+k-1][1]][lims[0][i+k-1][0]]++;

        int sum=0,pos=1;
        for(int j=0;j+k<=n;j++)
        {
            while(pos<=j+k)
            {
                for(auto y : ma[pos])
                    for(int k=0;k<y.second;k++)
                    {
                        update(y.first,1);
                        sum++;
                    }
                pos++;
            }
            m[i][j]+=(sum-query(j));
        }

        for(int j=0;j<MAXN;j++)
            abi[j]=0;
        if(lims[0][i][0])
            ma[lims[0][i][1]][lims[0][i][0]]--;
    }

    for(int i=0;i<MAXN;i++)
        ma[i].clear();

    for(int i=0;i<k-1;i++)
        if(lims[1][i][0])
            ma[lims[1][i][1]][lims[1][i][0]]++;

    for(int i=0;i+k<=n;i++)
    {
        if(lims[1][i+k-1][0])
            ma[lims[1][i+k-1][1]][lims[1][i+k-1][0]]++;

        int sum=0,pos=1;
        for(int j=0;j+k<=n;j++)
        {
            while(pos<=j+k)
            {
                for(auto y : ma[pos])
                    for(int k=0;k<y.second;k++)
                    {
                        update(y.first,1);
                        sum++;
                    }
                pos++;
            }
            m[j][i]+=(sum-query(j));
        }

        for(int j=0;j<MAXN;j++)
            abi[j]=0;
        if(lims[1][i][0])
            ma[lims[1][i][1]][lims[1][i][0]]--;
    }

    int res=b;
    for(int i=0;i+k<=n;i++)
        for(int j=0;j+k<=n;j++)
            res=max(res,b+m[i][j]);
    db(res)

    return 0;
}