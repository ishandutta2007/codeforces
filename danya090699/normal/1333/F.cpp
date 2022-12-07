#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int us[n+1], an[n+1], q=n;
    for(int a=0; a<=n; a++) us[a]=1, an[a]=0;
    for(int a=n; a; a--)
    {
        an[q]=a;
        for(int b=a+a; b<=n; b+=a) q-=us[b], us[b]=0;
    }
    for(int a=n-1; a; a--)
    {
        if(!an[a]) an[a]=an[a+1];
    }
    for(int a=2; a<=n; a++) printf("%d ", an[a]);
}