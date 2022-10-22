#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 105
#define p2 (1<<12)

int w[MAXN],cant[p2],n;
int abi[p2][p2];

void update(int d,int p,int x)
{
    while(p<p2)
    {
        abi[d][p]+=x;
        p+=(p&-p);
    }
}

int query(int d,int p)
{
    int res=0;
    while(p)
    {
        res+=abi[d][p];
        p-=(p&-p);
    }
    return res;
}

void preprocess()
{
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            int x=(1<<n)-(i^j)-1,sss=0;
            for(int u=0;u<n;u++)
                if(x&(1<<u))
                    sss+=w[u];
            if(cant[j])
                update(i,sss+1,cant[j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m,q,k;
    string s;
    cin >> n >> m >> q;
    for(int i=0;i<n;i++)
        cin >> w[n-i-1];
    for(int i=0;i<m;i++)
    {
        cin >> s;
        int num=0;
        for(int j=0;j<n;j++)
        {
            num*=2;
            if(s[j]=='1')
                num++;
        }
        cant[num]++;
    }

    preprocess();

    while(q--)
    {
        cin >> s >> k;
        int num=0;
        for(int j=0;j<n;j++)
        {
            num*=2;
            if(s[j]=='1')
                num++;
        }
//        for(auto y : sum[num])
//            cout << y.first << ' ' << y.second << '\n';
//        cout << '\n';
        db(query(num,k+1))
    }

    return 0;
}