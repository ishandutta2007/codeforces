#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, an=0;
    cin>>n>>m>>k;
    int ot[m][2];
    for(int a=0; a<m; a++)
    {
        cin>>ot[a][0]>>ot[a][1];
        ot[a][0]--;
    }
    for(int lg=0; lg+k<=n; lg++)
    {
        int su=0, add=0, add2[n+1];
        for(int a=lg; a<=n; a++) add2[a]=0;
        for(int a=0; a<m; a++)
        {
            int l=max(lg, ot[a][0]), r=min(lg+k, ot[a][1]), len=max(0, r-l);
            su+=len;
            if(ot[a][0]>lg and ot[a][1]>lg+k)
            {
                int d=min(k, ot[a][1]-ot[a][0])-len;
                int ll=max(lg+k, ot[a][0]), rr=ot[a][1]-len+k;
                //if(lg==0) cout<<ll<<" "<<rr<<"\n";
                add2[ll]++, add2[ll+d]--;
                if(rr-d<=n) add2[rr-d]--;
                if(rr<=n) add2[rr]++;
            }
        }
        for(int a=lg; a<=n; a++)
        {
            //if(su==3) cout<<lg<<" "<<a<<"\n";
            an=max(an, su);
            add+=add2[a];
            su+=add;
        }
    }
    cout<<an;
}