#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 105

int m[MAXN*MAXN*MAXN],ma[MAXN][2],d[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j]=200;
    for(int i=0;i<n;i++)
        d[i][i]=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<n;j++)
            if(s[j]=='1')
                d[i][j]=1;
    }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int a;
    cin>> a;
    vector<int> res;
    int ant,cant;
//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<n;j++)
//            cout << d[i][j] << ' ';
//    cout << '\n';
    for(int i=0;i<a;i++)
    {
        cin >> m[i];
        m[i]--;
        cant++;
        if(!i)
        {
            ant=m[i];
            cant=0;
            res.push_back(m[i]);
        }
        else
        {
            if(d[ant][m[i]]<cant)
            {
                res.push_back(m[i-1]);
                ant=m[i-1];
                cant=1;
            }
            if(i==a-1)
                res.push_back(m[i]);
        }
    }

    db(res.size())
    for(int i=0;i<res.size();i++)
        cout << res[i]+1 << ' ';
    cout << '\n';

    return 0;
}