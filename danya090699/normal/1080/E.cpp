#include <bits/stdc++.h>
using namespace std;
const int sz=300, mod=1e9+9, al=257;
int st[sz];
int main()
{
    st[0]=1;
    for(int a=1; a<sz; a++) st[a]=(1ll*st[a-1]*al)%mod;

    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    string fi[n];
    for(int a=0; a<n; a++) cin>>fi[a];
    /*int pref[n][m+1][26];
    for(int a=0; a<n; a++)
    {
        cin>>fi[a];
        for(int b=0; b<26; b++) pref[a][0][b]=0;
        for(int b=0; b<m; b++)
        {
            int sy=fi[a][b]-'a';
            for(int c=0; c<26; c++) pref[a][b+1][c]=pref[a][b][c];
            pref[a][b+1][sy]++;
        }
    }*/
    for(int lg=0; lg<m; lg++)
    {
        int qq[n][26], chash[n], badq[n];
        for(int a=0; a<n; a++)
        {
            chash[a]=0, badq[a]=0;
            for(int i=0; i<26; i++) qq[a][i]=0;
        }

        for(int rg=lg+1; rg<=m; rg++)
        {
            map <int, int> ma;
            int s[n];
            for(int a=0; a<n; a++)
            {
                int sy=fi[a][rg-1]-'a';

                chash[a]-=(1ll*qq[a][sy]*st[sy])%mod;
                if(chash[a]<0) chash[a]+=mod;

                badq[a]-=(qq[a][sy]&1);

                qq[a][sy]++;
                chash[a]=(chash[a]+1ll*qq[a][sy]*st[sy])%mod;

                badq[a]+=(qq[a][sy]&1);

                if(badq[a]>1) s[a]=-1;
                else
                {
                    if(ma.find(chash[a])==ma.end()) ma[chash[a]]=ma.size()-1;
                    s[a]=ma[chash[a]];
                }
            }
            int q=ma.size();
            for(int a=0; a<n; a++)
            {
                if(s[a]==-1) s[a]=q, q++;
            }

            int p1[n], p2[n-1], l=-1, r=-1;
            for(int a=0; a<n; a++)
            {
                p1[a]=0;
                if(a<=r) p1[a]=min(p1[l-(a-l)], r-a);
                while(p1[a]<a and p1[a]<(n-(a+1)))
                {
                    if(s[a-(p1[a]+1)]==s[a+(p1[a]+1)]) p1[a]++;
                    else break;
                }
                if(r<a+p1[a])
                {
                    r=a+p1[a], l=a;
                }
                if(s[a]<ma.size()) an+=1+p1[a];
            }
            l=-1, r=-1;
            for(int a=0; a<n-1; a++)
            {
                p2[a]=0;
                if(a<r) p2[a]=min(p2[l-(a-l)], r-a);
                while(p2[a]<(a+1) and p2[a]<(n-(a+1)))
                {
                    if(s[a-p2[a]]==s[a+(p2[a]+1)]) p2[a]++;
                    else break;
                }
                if(r<a+p2[a])
                {
                    r=a+p2[a], l=a;
                }
                an+=p2[a];
            }

            //cout<<lg<<" "<<rg<<" "<<an<<"\n";
        }
    }
    cout<<an;
}