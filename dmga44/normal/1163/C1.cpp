#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define pi (acos(-1))
#define MAXN 1005

int p[MAXN][2];
double g[MAXN][MAXN],mk[MAXN][MAXN];
map<double,vector<int>> g2[MAXN];

double calc(int i,int j)
{
    ld ix=p[i][0];
    ld iy=p[i][1];
    ld jx=p[j][0];
    ld jy=p[j][1];
    if(ix==jx)
        return pi/2.0;
    if(iy==jy)
        return 0;
    ix-=jx;
    iy-=jy;
    ld r=atan(iy/ix);
    if(r>pi)
        r-=pi;
    if(r<0)
        r+=pi;
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> p[i][0] >> p[i][1];

    map<double,int> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(j==i)
                continue;
            g[i][j]=calc(i,j);
            g2[i][g[i][j]].push_back(j);
        }

    set<double> s;
    ll sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(!mk[i][j] && i!=j)
            {
                s.insert(g[i][j]);
                m[g[i][j]]++;
                sum++;
                vector<int> in=g2[i][g[i][j]];
                in.push_back(i);
                for(auto ii : in)
                    for(auto jj : in)
                        if(ii!=jj)
                            mk[ii][jj]=1;
            }
        }

    int res=0;
    for(auto y : s)
        res+=(m[y]*(sum-m[y]));
    res/=2;

    db(res)

    return 0;
}