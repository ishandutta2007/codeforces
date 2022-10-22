#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mod ((ll)(2e9+99))
#define b ((ll)331)
#define MAXN 205

int s[MAXN][MAXN],ss[MAXN][MAXN],n,m;
ll h[MAXN][2],po[MAXN];
map<ll,int> fh[2];

bool check(int ii,int jj)
{
    for(int i=0;i<n;i++)
        if(s[i][jj])
            for(int j=0;j<m;j++)
                ss[i][j]=1-ss[i][j];
    for(int i=0;i<m;i++)
        if(s[ii][i])
            for(int j=0;j<n;j++)
                ss[j][i]=1-ss[j][i];
    bool res=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int ant=0;
            if(j)
                ant=ss[i][j-1];
            else if(i)
                ant=ss[i-1][m-1];
            res&=(ss[i][j]>=ant);
        }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    po[0]=1;
    for(int i=1;i<MAXN;i++)
        po[i]=(po[i-1]*b)%mod;

    cin >> n >> m;
    ll cn=0,cm=0;
    for(int i=0;i<n;i++)
        cn=(cn+po[i])%mod;
    for(int i=0;i<m;i++)
        cm=(cm+po[i])%mod;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> s[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ss[i][j]=s[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            h[i][0]=((h[i][0]*b)+s[i][j])%mod;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            h[i][1]=((h[i][1]*b)+s[j][i])%mod;

    for(int i=0;i<n;i++)
        fh[0][h[i][0]]++;
    for(int i=0;i<m;i++)
        fh[1][h[i][1]]++;

    bool ok=0;
    if(fh[0][h[0][0]]+fh[0][(cm+mod-h[0][0])%mod]==n &&
        fh[1][h[0][1]]+fh[1][(cn+mod-h[0][1])%mod]==m)
        {
            ok=1;
            db("YES")
            bool ko=check(0,0);
            for(int ii=0;ii<n;ii++)
                cout << (ko ? s[ii][0] : 1-s[ii][0] );
            cout << '\n';
            for(int jj=0;jj<m;jj++)
                cout << s[0][jj];
            cout << '\n';
        }

    for(int i=n-1;i>=0 && !ok;i--)
        for(int j=m-1;j>=0 && !ok;j--)
        {
            fh[0][h[i][0]]--;
            fh[1][h[j][1]]--;

            h[i][0]=(h[i][0]+mod-((s[i][j]*po[m-j-1])%mod))%mod;
            h[j][1]=(h[j][1]+mod-((s[i][j]*po[n-i-1])%mod))%mod;

            s[i][j]=(1-s[i][j]);

            h[i][0]=(h[i][0]+(s[i][j]*po[m-j-1])%mod)%mod;
            h[j][1]=(h[j][1]+(s[i][j]*po[n-i-1])%mod)%mod;

            fh[0][h[i][0]]++;
            fh[1][h[j][1]]++;

            if(fh[0][h[i][0]]+fh[0][(cm+mod-h[i][0])%mod]==n &&
               fh[1][h[j][1]]+fh[1][(cn+mod-h[j][1])%mod]==m)
            {
                ok=1;
                db("YES")
                bool ko=check(i,j);
                for(int ii=0;ii<n;ii++)
                    cout << (ko ? s[ii][j] : 1-s[ii][j] );
                cout << '\n';
                for(int jj=0;jj<m;jj++)
                    cout << s[i][jj];
                cout << '\n';
            }
        }
    if(!ok)
        db("NO")

    return 0;
}