#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    int n=s.size(), m=t.size();
    int pref[n+1][2], pref2[m+1][2];
    pref[0][0]=0, pref[0][1]=0, pref2[0][0]=0, pref2[0][1]=0;
    for(int a=0; a<n; a++)
    {
        pref[a+1][0]=pref[a][0], pref[a+1][1]=pref[a][1];
        if(s[a]=='A') pref[a+1][1]++;
        else
        {
            pref[a+1][0]++, pref[a+1][1]=0;
        }
    }
    for(int a=0; a<m; a++)
    {
        pref2[a+1][0]=pref2[a][0], pref2[a+1][1]=pref2[a][1];
        if(t[a]=='A') pref2[a+1][1]++;
        else
        {
            pref2[a+1][0]++, pref2[a+1][1]=0;
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l, r, l2, r2;
        scanf("%d%d%d%d", &l, &r, &l2, &r2);
        l--, l2--;
        int qb=pref[r][0]-pref[l][0], qb2=pref2[r2][0]-pref2[l2][0];
        int qa=pref[r][1], qa2=pref2[r2][1];
        if(qb==0) qa=r-l;
        if(qb2==0) qa2=r2-l2;
        if(qb2>=qb and (qb2-qb)%2==0 and qa2<=qa)
        {
            if(qb)
            {
                if(qb==qb2)
                {
                    if((qa-qa2)%3==0) cout<<1;
                    else cout<<0;
                }
                else cout<<1;
            }
            else
            {
                if(qb2==0)
                {
                    if((qa-qa2)%3==0) cout<<1;
                    else cout<<0;
                }
                else
                {
                    if(qa2<qa) cout<<1;
                    else cout<<0;
                }
            }
        }
        else cout<<0;
    }
}