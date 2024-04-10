#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    bool ok=0;
    auto in=[&](int r,int c)->bool{return (0<=r&&r<n&&0<=c&&c<n);};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!(i==0||i==n-1||j==0||j==n-1)) continue;
            for(int di=-1;di<=1;di++)
            {
                for(int dj=-1;dj<=1;dj++)
                {
                    if(di==0&&dj==0) continue;
                    if(!(di==1&&dj==1)) continue;
                    string t;
                    int r=i,c=j;
                    while(in(r,c)&&(int)t.size()<7)
                    {
                        t+=s[r][c];
                        r+=di;
                        c+=dj;
                    }
                    ok|=(t=="theseus");
                }
            }
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}