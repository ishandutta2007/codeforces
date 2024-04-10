#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<array<int,2>> v(4);
    for(int i=0;i<4;i++) cin >> v[i][0] >> v[i][1];
    //0-win1 1-draw 2-win2
    int res=2;
    for(int i=0;i<2;i++)
    {
        int a=v[i][0];
        int b=v[1-i][1];
        int now=0;
        for(int j=2;j<4;j++)
        {
            int c=v[j][0];
            int d=v[5-j][1];
            if(c>b&&d>a) now=2;
            else if(!(b>c&&a>d)) now=max(now,1);
        }
        res=min(res,now);
    }
    if(res==0) cout << "Team 1\n";
    else if(res==1) cout << "Draw\n";
    else cout << "Team 2\n";
    return 0;
}