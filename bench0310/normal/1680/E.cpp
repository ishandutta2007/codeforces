#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<string> s(2);
        cin >> s[0] >> s[1];
        int l=0;
        while(s[0][l]=='.'&&s[1][l]=='.') l++;
        int r=n-1;
        while(s[0][r]=='.'&&s[1][r]=='.') r--;
        array<int,2> now={-1,-1};
        for(int i=l;i<=r;i++)
        {
            array<int,2> nxt={2*n,2*n};
            char x=s[0][i],y=s[1][i];
            if(x=='.'&&y=='.') for(int j=0;j<2;j++) nxt[j]=now[j]+1;
            else if(x=='*'&&y=='*') nxt[0]=nxt[1]=min(now[0],now[1])+2;
            else
            {
                int p=(y=='*');
                nxt[p]=now[p]+1;
                nxt[p^1]=min(now[0],now[1])+2;
            }
            now=nxt;
        }
        cout << min(now[0],now[1]) << "\n";
    }
    return 0;
}