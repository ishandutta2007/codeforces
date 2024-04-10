#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size();
    int suf[n+1][26];
    for(int a=0; a<26; a++) suf[0][a]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<26; b++) suf[a+1][b]=suf[a][b];
        suf[a+1][s[a]-'a']++;
    }
    int m;
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        if(r-l==1 or s[l]!=s[r-1]) printf("Yes\n");
        else
        {
            int dif=0;
            for(int b=0; b<26; b++) if(suf[l][b]!=suf[r][b]) dif++;
            //cout<<dif<<"\n";
            if(dif>2) printf("Yes\n");
            else printf("No\n");
        }
    }
}