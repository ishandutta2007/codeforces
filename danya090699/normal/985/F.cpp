#include <bits/stdc++.h>
using namespace std;
const int al=5, mod=1e9+9, sz=2e5+10;
int pref[26][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    int st[n];
    st[0]=1;
    for(int a=1; a<n; a++) st[a]=(1ll*al*st[a-1])%mod;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<26; b++) pref[b][a+1]=pref[b][a];
        pref[s[a]-'a'][a+1]+=st[a];
        pref[s[a]-'a'][a+1]%=mod;
    }
    for(int a=0; a<m; a++)
    {
        int x, y, l;
        scanf("%d%d%d", &x, &y, &l);
        x--, y--;
        int ha[2][26];
        for(int b=0; b<26; b++)
        {
            ha[0][b]=pref[b][x+l]-pref[b][x];
            if(ha[0][b]<0) ha[0][b]+=mod;
            ha[0][b]=(1ll*st[n-x-l]*ha[0][b])%mod;

            ha[1][b]=pref[b][y+l]-pref[b][y];
            if(ha[1][b]<0) ha[1][b]+=mod;
            ha[1][b]=(1ll*st[n-y-l]*ha[1][b])%mod;
        }
        bool ok=1;
        sort(ha[0], ha[0]+26), sort(ha[1], ha[1]+26);
        for(int b=0; b<26; b++) if(ha[0][b]!=ha[1][b]) ok=0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
}