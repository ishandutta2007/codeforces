#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    n=n*4+1;
    int ar[n][2];
    for(int a=0; a<n; a++) cin>>ar[a][0]>>ar[a][1];
    for(int a=0; a<n; a++)
    {
        int l[2]={inf, inf}, r[2]={-inf, -inf};
        for(int b=0; b<n; b++)
        {
            if(b!=a)
            {
                for(int i=0; i<2; i++) l[i]=min(l[i], ar[b][i]), r[i]=max(r[i], ar[b][i]);
            }
        }
        if(r[0]-l[0]==r[1]-l[1])
        {
            int q=0;
            for(int i=0; i<2; i++)
            {
                if(ar[a][i]!=l[i] and ar[a][i]!=r[i]) q++;
                if(ar[a][i]<l[i] or ar[a][i]>r[i]) q+=2;
            }
            if(q>1)
            {
                cout<<ar[a][0]<<" "<<ar[a][1];
                return 0;
            }
        }
    }
}