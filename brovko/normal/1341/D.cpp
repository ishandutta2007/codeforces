#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int INF=1000000000;

int n, k, r[2005][2005], q[2005][10];
string a[2005], p[10];
vector <int> ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    p[0]="1110111";
    p[1]="0010010";
    p[2]="1011101";
    p[3]="1011011";
    p[4]="0111010";
    p[5]="1101011";
    p[6]="1101111";
    p[7]="1010010";
    p[8]="1111111";
    p[9]="1111011";

    for(int i=0;i<n;i++)
        for(int j=0;j<10;j++)
    {
        for(int k=0;k<7;k++)
            if(p[j][k]>a[i][k])
                q[i][j]++;
            else if(p[j][k]<a[i][k])
                    q[i][j]=INF;
    }

    for(int j=0;j<10;j++)
        if(q[n-1][j]<2005)
            r[n-1][q[n-1][j]]=1;

    for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<2005;j++)
            if(r[i][j]==1)
                for(int k=0;k<10;k++)
                    if(j+q[i-1][k]<2005)
                        r[i-1][j+q[i-1][k]]=1;
    }
    r[n][0]=1;

    if(r[0][k]==0)
    {
        cout << -1;
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        int Max=0;
        for(int j=0;j<10;j++)
        {
            if(k-q[i][j]>=0)
                if(r[i+1][k-q[i][j]])
                    Max=j;
        }
        ans.push_back(Max);
        k-=q[i][Max];
    }

    for(auto to:ans)
        cout << to;
}