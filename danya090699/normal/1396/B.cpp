#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n], us=-1, i=0;
        for(int a=0; a<n; a++) cin>>ar[a];
        while(1)
        {
            int be=0, p;
            for(int a=0; a<n; a++)
            {
                if(a!=us and ar[a]>be) be=ar[a], p=a;
            }
            if(be)
            {
                us=p, ar[p]--, i^=1;
            }
            else
            {
                if(i) cout<<"T\n";
                else cout<<"HL\n";
                break;
            }
        }
    }
}