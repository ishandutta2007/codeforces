#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], suf[n+1];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    suf[n]=0;
    for(int a=n-1; a>=0; a--) suf[a]=(suf[a+1]|ar[a]);
    int pref=0, be=-1, va=-1;
    for(int a=0; a<n; a++)
    {
        int su=0;
        for(int i=0; i<30; i++)
        {
            if(ar[a]&(1<<i))
            {
                if(((pref|suf[a+1])&(1<<i))==0) su+=(1<<i);
            }
        }
        if(su>va) va=su, be=a;
        pref|=ar[a];
    }
    cout<<ar[be];
    for(int a=0; a<n; a++) if(a!=be) printf(" %d", ar[a]);
}