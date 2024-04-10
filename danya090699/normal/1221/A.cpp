#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int n;
        cin>>n;
        int ar[30];
        for(int i=0; i<30; i++) ar[i]=0;
        for(int a=0; a<n; a++)
        {
            int x, st=0;
            cin>>x;
            while(x%2==0) x/=2, st++;
            ar[st]++;
        }
        for(int i=0; i<=10; i++) ar[i+1]+=ar[i]/2;
        if(ar[11]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}