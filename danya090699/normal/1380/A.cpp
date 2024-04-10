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
        int ar[n], ok=0;
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        for(int a=0; a+2<n; a++)
        {
            if(ar[a]<ar[a+1] and ar[a+1]>ar[a+2])
            {
                cout<<"YES\n"<<a+1<<" "<<a+2<<" "<<a+3<<"\n";
                ok=1;
                break;
            }
        }
        if(!ok) cout<<"NO\n";
    }
}