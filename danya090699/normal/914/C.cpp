#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), k;
    cin>>k;
    if(k==0) cout<<1;
    else
    {
        int q[n+1], tr[n+1][n+1];
        for(int a=1; a<=n; a++)
        {
            q[a]=0;
            int cu=a;
            while(cu>1)
            {
                q[a]++;
                int x=0;
                for(int i=0; i<20; i++) if(cu&(1<<i)) x++;
                cu=x;
            }
        }
        for(int a=0; a<=n; a++)
        {
            tr[a][0]=1, tr[a][a]=1;
            for(int b=1; b<a; b++) tr[a][b]=(tr[a-1][b-1]+tr[a-1][b])%mod;
        }
        int qq=0, an=0;
        for(int a=0; a<n; a++)
        {
            if(s[a]=='1')
            {
                for(int b=0; b<=(n-a-1); b++)
                {
                    int vq=tr[n-a-1][b];
                    if(qq==0 and b==1) vq--;
                    if(vq<0) vq+=mod;
                    if(qq+b>0 and q[qq+b]+1==k)
                    {
                        //cout<<b<<" "<<vq<<"\n";
                        an=(an+vq)%mod;
                    }
                }
                qq++;
            }

        }
        if(n!=1)
        {
            if(q[qq]+1==k) an=(an+1)%mod;
        }
        cout<<an;
    }
}