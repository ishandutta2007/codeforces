#include <bits/stdc++.h>

using namespace std;

const int N=1000000+5;
int n;
string a,b;
int ap[2][2];

int f[N],s[N],xf,xs;
int poz=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    for(int i=0;i<2*n;i++)
    {
        int x=a[i]-'0';
        int y=b[i]-'0';
        ap[x][y]++;
    }
    for(int k=1;ap[1][1];k=1-k)
    {
        poz=1-poz;
        if(k==1)
            f[++xf]=1;
        else
            s[++xs]=1;
        ap[1][1]--;
    }
    while(xf<n || xs<n)
    {
        poz=1-poz;
        if(poz==1)
        {
            if(ap[1][0])
            {
                f[++xf]=1;
                ap[1][0]--;
                continue;
            }
            if(ap[0][1])
            {
                f[++xf]=0;
                ap[0][1]--;
                continue;
            }
            f[++xf]=0;
            ap[0][0]--;
            continue;
        }
        if(ap[0][1])
        {
            s[++xs]=1;
            ap[0][1]--;
            continue;
        }
        if(ap[1][0])
        {
            s[++xs]=0;
            ap[1][0]--;
            continue;
        }
        s[++xs]=0;
        ap[0][0]--;
    }
    for(int i=1;i<=n;i++)
        if(f[i]!=s[i])
        {
            if(f[i]>s[i])
                cout<<"First\n";
            else
                cout<<"Second\n";
            return 0;
        }
    cout<<"Draw\n";
    return 0;
}
/**

**/