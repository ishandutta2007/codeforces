#include <bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<"Second"<<"\n";
        int to[n*2+1], nu[n*2+1], va[n+1], an[n+1];
        for(int a=1; a<=n; a++) va[a]=0;
        for(int a=1; a<=2*n; a++)
        {
            cin>>nu[a];
            if(va[nu[a]])
            {
                to[va[nu[a]]]=a;
                to[a]=va[nu[a]];
            }
            else va[nu[a]]=a;
        }
        bool us[n];
        for(int a=0; a<n; a++) us[a]=0;
        int su=0;
        for(int a=1; a<=n; a++)
        {
            int v=a;
            while(!us[v%n])
            {
                us[v%n]=1;
                an[nu[v]]=v, su=(su+v)%(2*n);
                v=(v<=n) ? v+n : v-n;
                v=to[v];
            }
        }
        for(int a=1; a<=n; a++)
        {
            printf("%d ", su ? to[an[a]] : an[a]);
        }
        cout<<"\n";
    }
    else
    {
        cout<<"First"<<"\n";
        for(int i=0; i<2; i++) for(int a=1; a<=n; a++) printf("%d ", a);
        cout<<"\n";
    }
    int an;
    cin>>an;
}