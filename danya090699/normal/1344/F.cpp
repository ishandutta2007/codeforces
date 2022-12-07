#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10;
bitset <sz> ma[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int va[n*2];
    for(int a=0; a<n*2; a++)
    {
        if(a&1) va[a]=2;
        else va[a]=1;
    }
    for(int a=0; a<k; a++)
    {
        string ty;
        cin>>ty;
        if(ty=="mix")
        {
            int q;
            cin>>q;
            bitset <sz> r[2];
            for(int b=0; b<q; b++)
            {
                int i;
                scanf("%d", &i);
                i--;

                if(va[i*2]&1) r[0][i*2]=1;
                if(va[i*2]&2) r[0][i*2+1]=1;

                if(va[i*2+1]&1) r[1][i*2]=1;
                if(va[i*2+1]&2) r[1][i*2+1]=1;
            }
            char sy;
            cin>>sy;
            if(sy=='R') r[0][n*2]=1;
            if(sy=='Y') r[1][n*2]=1;
            if(sy=='B') r[0][n*2]=1, r[1][n*2]=1;

            for(int b=0; b<2; b++)
            {
                bool ins=0;
                for(int i=0; i<n*2; i++)
                {
                    if(r[b][i])
                    {
                        if(ma[i][i]) r[b]^=ma[i];
                        else
                        {
                            ma[i]=r[b], ins=1;
                            break;
                        }
                    }
                }
                if(!ins and r[b][n*2])
                {
                    cout<<"NO";
                    return 0;
                }
            }
        }
        else
        {
            int q;
            cin>>q;
            for(int b=0; b<q; b++)
            {
                int i;
                scanf("%d", &i);
                i--;
                int x1=va[i*2], x2=va[i*2+1];
                if(ty=="RY")
                {
                    va[i*2]=x2, va[i*2+1]=x1;
                }
                if(ty=="RB")
                {
                    va[i*2]=x1, va[i*2+1]=x1^x2;
                }
                if(ty=="YB")
                {
                    va[i*2]=x1^x2, va[i*2+1]=x2;
                }
            }
        }
    }
    int an[n*2];
    for(int a=n*2-1; a>=0; a--)
    {
        if(ma[a][a])
        {
            an[a]=ma[a][n*2];
            for(int b=a-1; b>=0; b--) if(ma[b][a]) ma[b]^=ma[a];
        }
        else an[a]=0;
    }
    cout<<"YES\n";
    for(int a=0; a<n*2; a+=2)
    {
        int i=an[a]+(an[a+1]<<1);
        if(i==0) cout<<'.';
        if(i==1) cout<<'R';
        if(i==2) cout<<'Y';
        if(i==3) cout<<'B';
    }
}