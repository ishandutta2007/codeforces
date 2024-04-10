#include <bits/stdc++.h>

using namespace std;

const int N=100;
int n,k;
char s[N+5];
int v[N+5][N+5];
int nr[N+5][N+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        cin.getline(s,N+5);
        for(int j=0;j<n;j++)
            if(s[j]=='.')
                v[i][j+1]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j+k-1<=n;j++)
        {
            int st=j;
            int dr=j+k-1;
            bool ok=1;
            for(int p=st;p<=dr;p++)
                if(v[i][p]==0)
                {
                    ok=0;
                    break;
                }
            if(ok==0)
                continue;
            for(int p=st;p<=dr;p++)
                nr[i][p]++;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j+k-1<=n;j++)
        {
            int st=j;
            int dr=j+k-1;
            bool ok=1;
            for(int p=st;p<=dr;p++)
                if(v[p][i]==0)
                {
                    ok=0;
                    break;
                }
            if(ok==0)
                continue;
            for(int p=st;p<=dr;p++)
                nr[p][i]++;
        }
    int best=0,r=1,c=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(nr[i][j]>best)
            {
                best=nr[i][j];
                r=i;
                c=j;
            }
        }
    cout<<r<<" "<<c;
    return 0;
}
/**


**/