#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    char s[n+1], t[n+1];
    scanf("%s%s", s, t);
    int an=n, q=0, l=0;
    k--;
    for(l=0; l<n; l++)
    {
        if(s[l]!=t[l])
        {
            if(k) an+=n-l, k--;
            break;
        }
    }
    l++;
    for(l; (l<n and k>0); l++)
    {
        int nq=q;
        if(s[l]=='a') nq++;
        if(t[l]=='b') nq++;
        an+=min(nq, k)*(n-l);
        k-=min(nq, k);
        q+=nq;
    }
    cout<<an;
}