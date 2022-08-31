#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,a;
    cin>>t;
    char s[105][105];
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        for(int j=1;j<=n;j++)
        {
           a=((j%k==0)?k:j%k);
           s[i][j-1]=a+96;
        }
s[i][n]=0;
    }
    for(int i=0;i<t;i++)
        printf("%s \n",s[i]);
}