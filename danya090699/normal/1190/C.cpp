#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int pref[n+1], suf[n+1];
    string s;
    cin>>s;
    pref[0]=0;
    for(int a=1; a<=n; a++) pref[a]=pref[a-1]+(s[a-1]=='1');
    suf[n]=0;
    for(int a=n-1; a>=0; a--) suf[a]=suf[a+1]+(s[a]=='1');
    int bad=0;
    for(int a=0; a+k<=n; a++)
    {
        int l[2]={a-pref[a], pref[a]}, r[2]={n-a-k-suf[a+k], suf[a+k]};
        for(int i=0; i<2; i++)
        {
            if(l[i^1]==0 and r[i^1]==0)
            {
                cout<<"tokitsukaze";
                return 0;
            }
            if((r[i^1]==0 and a<=k) or (l[i^1]==0 and n-a-k<=k)) bad++;
        }
    }
    if(bad==2*(n-k+1)) cout<<"quailty";
    else cout<<"once again";
}