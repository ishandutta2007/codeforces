#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 505

string s[MAXN];
int m[MAXN][MAXN],ac1[MAXN][MAXN],last[MAXN][MAXN];
int ac2[MAXN/2][MAXN][MAXN];

int q1(int x1,int y1,int x2,int y2)
{
    return ac1[x2+1][y2+1]-ac1[x1][y2+1]-ac1[x2+1][y1]+ac1[x1][y1];
}

int q2(int d,int x1,int y1,int x2,int y2)
{
    return ac2[d][x2+1][y2+1]-ac2[d][x1][y2+1]-ac2[d][x2+1][y1]+ac2[d][x1][y1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,mm,q;
    cin >> n >> mm >> q;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        last[i][0]=-1;
        for(int j=0;j<mm;j++)
        {
            if(s[i][j]=='R')
                m[i][j]=0;
            if(s[i][j]=='G')
                m[i][j]=1;
            if(s[i][j]=='Y')
                m[i][j]=2;
            if(s[i][j]=='B')
                m[i][j]=3;
            last[i][j+1]=last[i][j];
            if(m[i][j]!=3)
                last[i][j+1]=j;
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<mm;j++)
            ac1[i+1][j+1]=m[i][j]+ac1[i][j+1]+ac1[i+1][j]-ac1[i][j];

    for(int i=1;i<n;i++)
        for(int j=1;j<mm;j++)
        {
            int tam=j-last[i][j+1];
            if(tam && i+1>=tam*2 && j+1>=tam*2)
            {
                int qs1=q1(i-2*tam+1,j-2*tam+1,i-tam,j-tam);
                int qs2=q1(i-2*tam+1,j-tam+1,i-tam,j);
                int qs3=q1(i-tam+1,j-2*tam+1,i,j-tam);
                int qs4=q1(i-tam+1,j-tam+1,i,j);
                if(qs1==0 && qs2==tam*tam && qs3==tam*tam*2 && qs4==tam*tam*3)
                {
//                    cout << tam << ' ' << i << ' ' << j << '\n';
                    ac2[tam][i+1][j+1]=1;
                }
            }

            for(int k=1;k<MAXN/2;k++)
                ac2[k][i+1][j+1]=ac2[k][i+1][j+1]+ac2[k][i][j+1]+ac2[k][i+1][j]-ac2[k][i][j];
        }


//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<mm;j++)
//            cout << m[i][j] << ' ';
//    db("")
//    for(int i=0;i<=n;i++,cout << '\n')
//        for(int j=0;j<=mm;j++)
//            cout << ac1[i][j] << ' ';
//    db("")


    while(q--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2--;
        y2--;
        int res=0,d=1;
        while(x1<=x2 && y1<=y2)
        {
            if(q2(d,x1,y1,x2,y2))
                res=max(res,d);
            x1+=2;
            y1+=2;
            d++;
        }
        res*=2;
        db(res*res)
    }

    return 0;
}