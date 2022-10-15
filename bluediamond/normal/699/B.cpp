#include <bits/stdc++.h>

using namespace std;

const int nmax=1000;
int n,m;
int ap_r[nmax+5],ap_c[nmax+5],v[nmax+5][nmax+5];
int total=0;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin.get();
        for(int j=1;j<=m;j++)
        {
            char ch;
            ch=cin.get();
            if(ch=='*')
            {
                v[i][j]=1;
                total++;
                ap_r[i]++;
                ap_c[j]++;
            }
        }
    }
    for(int r=1;r<=n;r++)
        for(int c=1;c<=m;c++)
        {
            int nr=0;
            nr+=ap_r[r];
            nr+=ap_c[c];
            if(v[r][c]==1)
                nr--;
            if(nr==total)
            {
                cout<<"YES\n";
                cout<<r<<" "<<c;
                return 0;
            }
        }
    cout<<"NO";
    return 0;
}
/**

**/