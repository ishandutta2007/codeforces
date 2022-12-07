#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> pref[sz], suf[sz], prefq[sz], sufq[sz];
int prefva[sz][26], sufva[sz][26], l[sz][26], r[sz][26], su[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size();
    vector <int> sp[26];
    for(int a=0; a<26; a++) sp[a].push_back(-1);
    for(int a=0; a<n; a++)
    {
        sp[s[a]-'a'].push_back(a);
        pref[a].push_back(0), suf[a].push_back(0);
    }
    for(int a=0; a<26; a++)
    {
        sp[a].push_back(n);
        for(int b=1; b<sp[a].size(); b++)
        {
            int pr=sp[a][b-1], cu=sp[a][b];
            for(int c=pr+1; c<cu; c++)
            {
                l[c][a]=pr, r[c][a]=cu;
            }
            l[cu][a]=cu, r[cu][a]=cu;
            for(int c=1; c<=cu-pr-1; c++)
            {
                prefq[c].push_back(pr), sufq[c].push_back(cu);
            }
        }
    }
    for(int a=1; a<=n; a++)
    {
        for(int b=0; b<prefq[a].size(); b++)
        {
            int p=prefq[a][b], us[35];
            for(int c=0; c<35; c++) us[c]=0;
            for(int c=0; c<26; c++)
            {
                if(s[p+a]-'a'==c)
                {
                    int pr=p;
                    if(p+a) pr=max(pr, l[p+a-1][c]);
                    prefva[p][c]^=suf[p+a][(p+a)-pr-1];
                }
                int pr=l[p+a][c];
                if(pr>p)
                {
                    int va=prefva[p][c]^pref[pr][(p+a)-pr];
                    us[va]=1;
                }
            }
            for(int c=0; ; c++)
            {
                if(us[c]==0)
                {
                    pref[p].push_back(c);
                    break;
                }
            }
        }
        for(int b=0; b<sufq[a].size(); b++)
        {
            int p=sufq[a][b], us[35];
            for(int c=0; c<35; c++) us[c]=0;
            for(int c=0; c<26; c++)
            {
                if(s[p-a]-'a'==c)
                {
                    int pr=p;
                    if(p-a+1<n) pr=min(pr, r[p-a+1][c]);
                    sufva[p][c]^=pref[p-a][pr-(p-a)-1];
                }
                int pr=r[p-a][c];
                if(pr<p)
                {
                    int va=sufva[p][c]^suf[pr][pr-(p-a)];
                    us[va]=1;
                }
            }
            for(int c=0; ; c++)
            {
                if(us[c]==0)
                {
                    suf[p].push_back(c);
                    break;
                }
            }
        }
    }
    for(int a=0; a<26; a++)
    {
        for(int b=1; b+1<sp[a].size(); b++)
        {
            int pr=sp[a][b-1], cu=sp[a][b];
            su[cu]=suf[cu][cu-pr-1];
            if(pr>=0) su[cu]^=su[pr];
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int lg, rg;
        scanf("%d%d", &lg, &rg);
        lg--, rg--;
        int us[35];
        for(int b=0; b<35; b++) us[b]=0;
        for(int b=0; b<26; b++)
        {
            int ll=r[lg][b], rr=l[rg][b];
            if(ll<=rr)
            {
                int va=suf[ll][ll-lg]^(su[rr]^su[ll])^pref[rr][rg-rr];
                us[va]=1;
            }
        }
        if(us[0]) printf("Alice\n");
        else printf("Bob\n");
    }
}