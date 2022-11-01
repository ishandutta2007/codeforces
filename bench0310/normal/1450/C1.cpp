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
        array<int,3> c={0,0,0};
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) c[m(i-j)]+=(s[i][j]=='X');
        int k=c[0]+c[1]+c[2];
        int x=-1;
        for(int i=0;i<3;i++) if(c[i]<=k/3) x=i;
        assert(x!=-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[i][j]=='X'&&m(i-j)==x) s[i][j]='O';
                cout << s[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}