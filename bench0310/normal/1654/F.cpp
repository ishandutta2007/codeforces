#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> now(1<<n);
    for(int i=0;i<(1<<n);i++) now[i].push_back(s[i]-'a');
    for(int b=0;b<n;b++)
    {
        vector<vector<int>> nxt(1<<n);
        vector<array<int,4>> h;
        for(int i=0;i<(1<<n);i+=(1<<(b+1)))
        {
            nxt[i].resize(1<<(b+1));
            for(int j=0;j<(1<<b);j++) h.push_back({now[i][j],now[i+(1<<b)][j],i,j});
            for(int j=0;j<(1<<b);j++) h.push_back({now[i+(1<<b)][j],now[i][j],i,j^(1<<b)});
        }
        ranges::sort(h);
        int id=0;
        for(int i=0;i<(1<<n);i++)
        {
            if(i==0||h[i-1][0]!=h[i][0]||h[i-1][1]!=h[i][1]) id++;
            nxt[h[i][2]][h[i][3]]=id;
        }
        now=nxt;
    }
    int opt=0;
    for(int i=0;i<(1<<n);i++) if(now[0][i]<now[0][opt]) opt=i;
    for(int i=0;i<(1<<n);i++) cout << s[i^opt];
    cout << "\n";
    return 0;
}