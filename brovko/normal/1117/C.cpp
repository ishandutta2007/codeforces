#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int x1, y1, x2, y2, x, y, dx[100005], dy[100005], n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;

    for(int i=1;i<=n;i++)
    {
        dx[i]=dx[i-1];
        dy[i]=dy[i-1];
        if(s[i-1]=='U')
            dy[i]++;
        if(s[i-1]=='D')
            dy[i]--;
        if(s[i-1]=='L')
            dx[i]--;
        if(s[i-1]=='R')
            dx[i]++;
    }

    int L=0;
    int R=1e15;
    while(R-L>1)
    {
        int M=(L+R)/2;
        int p=M/n;
        int q=M%n;

        int Dx=dx[n]*p+dx[q];
        int Dy=dy[n]*p+dy[q];

        if(M>=abs(x1+Dx-x2)+abs(y1+Dy-y2))
            R=M;
        else L=M;
    }
    if(R==(int)1e15)
        cout << -1;
    else
    cout << R;
}