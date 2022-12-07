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
        int ar[n][3], an[n];
        for(int i=0; i<3; i++) for(int a=0; a<n; a++) cin>>ar[a][i];
        an[0]=ar[0][0];
        for(int a=1; a<n; a++)
        {
            for(int i=0; i<3; i++)
            {
                bool ok=1;
                if(ar[a][i]==an[a-1]) ok=0;
                if(a==n-1 and ar[a][i]==an[0]) ok=0;

                if(ok)
                {
                    an[a]=ar[a][i];
                    break;
                }
            }
        }
        for(int a=0; a<n; a++) cout<<an[a]<<" ";
        cout<<"\n";
    }
}