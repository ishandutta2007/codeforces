#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 300005

int p[MAXN],t[MAXN],pg[MAXN];
vector<int> pos[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int mr=-1,mg=-1,mb=-1;
    int index=0;
    for(int i=0;i<n;i++)
    {
        char c;
        cin >> p[i] >> c;

        if(c=='R')
            t[i]=1;
        if(c=='G')
        {
            pg[index]=p[i];
            t[i]=0;
            index++;
        }
        if(c=='B')
            t[i]=2;
        if(t[i])
            pos[index][t[i]-1].push_back(p[i]);
    }

    if(index==0)
    {
        if(pos[0][0].size()==0)
            pos[0][0].push_back(0);
        if(pos[0][1].size()==0)
            pos[0][1].push_back(0);
        db(pos[0][0][pos[0][0].size()-1]+pos[0][1][pos[0][1].size()-1]-pos[0][0][0]-pos[0][1][0])
    }
    else
    {
        ll res=0;
        for(int i=0;i<=index;i++)
        {
            if(i==0)
            {
                if(pos[0][0].size()==0)
                    pos[0][0].push_back(pg[0]);
                res+=pg[0]-pos[0][0][0];
                if(pos[0][1].size()==0)
                    pos[0][1].push_back(pg[0]);
                res+=pg[0]-pos[0][1][0];
            }
            else if(i==index)
            {
                if(pos[index][0].size()==0)
                    pos[index][0].push_back(pg[index-1]);
                res+=pos[index][0][pos[index][0].size()-1]-pg[index-1];
                if(pos[index][1].size()==0)
                    pos[index][1].push_back(pg[index-1]);
                res+=pos[index][1][pos[index][1].size()-1]-pg[index-1];
            }
            else
            {
                ll dif=pg[i]-pg[i-1];
                ll m[2];
                m[0]=m[1]=0;

                ll last=pg[i-1];
                for(auto y : pos[i][0])
                {
                    m[0]=max(m[0],y-last);
                    last=y;
                }
                m[0]=max(m[0],pg[i]-last);

                last=pg[i-1];
                for(auto y : pos[i][1])
                {
                    m[1]=max(m[1],y-last);
                    last=y;
                }
                m[1]=max(m[1],pg[i]-last);

                if(m[0]+m[1]>=dif)
                {
                    res+=3*dif-m[0]-m[1];
                }
                else
                {
                    res+=2*dif;
                }
            }
        }
        db(res)
    }

    return 0;
}
/**
4
1 G
5 R
10 B
15 G

4
1 G
2 R
3 B
10 G
**/