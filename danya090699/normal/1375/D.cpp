#include <bits/stdc++.h>
using namespace std;
int mex(int *ar, int n)
{
    bool us[n+1];
    for(int a=0; a<=n; a++) us[a]=0;
    for(int a=0; a<n; a++) us[ar[a]]=1;
    for(int a=0; ; a++)
    {
        if(!us[a]) return a;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n], us[n];
        vector <int> an;
        for(int a=0; a<n; a++) scanf("%d", &ar[a]), us[a]=0;
        for(int a=0; a<n; a++)
        {
            int x=mex(ar, n);
            //cout<<x<<" ";
            if(x==n)
            {
                for(int a=0; a<n; a++)
                {
                    if(!us[a])
                    {
                        ar[a]=x;
                        an.push_back(a+1);
                        break;
                    }
                }
                x=mex(ar, n);
            }
            //cout<<x<<" ";
            ar[x]=x, us[x]=1, an.push_back(x+1);
        }
        cout<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
        cout<<"\n";
    }
}