#include <bits/stdc++.h>
using namespace std;
int n,d,mat[105][105],day[105];
char ch;
int main()
{
    cin>>n>>d;
    for(int i=1;i<=d;i++)
    {
        cin.get();
        for(int j=1;j<=n;j++)
        {
            ch=cin.get();
            mat[i][j]=ch-'0';
        }
    }
    for(int i=1;i<=d;i++)
    {
        day[i]=0;
        for(int j=1;j<=n;j++)
            if(mat[i][j]==0)
                day[i]=1;
    }
    day[0]=0;
    day[d+1]=0;
    int l=0,lmax=0;
    for(int i=0;i<=d+1;i++)
    {
        if(day[i]==0)
        {
            lmax=max(lmax,l);
            l=0;
            continue;
        }
        l++;
    }
    cout<<lmax;
    return 0;
}