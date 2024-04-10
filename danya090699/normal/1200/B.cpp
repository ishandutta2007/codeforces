#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, m, k, ok=1;
        cin>>n>>m>>k;
        int h[n];
        for(int a=0; a<n; a++) scanf("%d", &h[a]);
        for(int a=0; a+1<n; a++)
        {
            if(h[a]+k<=h[a+1])
            {
                if(m<h[a+1]-k-h[a])
                {
                    ok=0;
                    break;
                }
                else m-=h[a+1]-k-h[a];
            }
            else m+=h[a]-max(h[a+1]-k, 0);
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}