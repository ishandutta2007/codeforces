#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    auto m=[](int a)->int{return ((a%3)+3)%3;};
    while(t--)
    {
        int n;
        cin >> n;
        vector<string> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        array<int,3> x={0,0,0};
        array<int,3> o={0,0,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                x[m(i-j)]+=(s[i][j]=='X');
                o[m(i-j)]+=(s[i][j]=='O');
            }
        }
        int k=x[0]+x[1]+x[2]+o[0]+o[1]+o[2];
        int a=-1,b=-1;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i!=j&&x[i]+o[j]<=k/3) tie(a,b)={i,j};
        assert(a!=-1&&b!=-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[i][j]=='X'&&m(i-j)==a) s[i][j]='O';
                if(s[i][j]=='O'&&m(i-j)==b) s[i][j]='X';
                cout << s[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}