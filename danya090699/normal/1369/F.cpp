#include <bits/stdc++.h>
#define int long long
using namespace std;
int win(int s, int e)
{
    if(e&1) return (s&1)^1;
    else
    {
        if(s*2>e) return s&1;
        else if(s*4>e) return 1;
        else return win(s, e/4);
    }
}
int lose(int s, int e)
{
    if(s*2>e) return 1;
    else return win(s, e/2);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    int s[t], e[t], w[t], l[t];
    for(int a=0; a<t; a++) scanf("%lld%lld", &s[a], &e[a]);
    w[t-1]=win(s[t-1], e[t-1]);
    l[t-1]=lose(s[t-1], e[t-1]);
    for(int a=t-2; a>=0; a--)
    {
        if(w[a+1]) w[a]=lose(s[a], e[a]);
        else w[a]=win(s[a], e[a]);

        if(l[a+1]) l[a]=lose(s[a], e[a]);
        else l[a]=win(s[a], e[a]);
    }
    cout<<w[0]<<" "<<l[0];
}