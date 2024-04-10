#include <iostream>
using namespace std;
int s[1005];
int t[1005];
int che[1005];
int main()
{
    int m,n,i,j;
    char ch;
    cin>>m>>n;
    cin.get();
    for(i=1;i<=m;i++)
        {
        ch=cin.get();
        s[i]=ch;
        }
    cin.get();
    for(i=1;i<=n;i++)
        {
        ch=cin.get();
        t[i]=ch;
        }
    for(i=1;i+m-1<=n;i++)
        for(j=i;j<=i+m-1;j++)
            if(s[j-i+1]!=t[j])
                che[i]++;
    int mi=99999,poz;
    for(i=1;i+m-1<=n;i++)
        if(che[i]<mi)
        {
            mi=che[i];
            poz=i;
        }
    cout<<mi<<"\n";
    for(j=poz;j<=poz+m-1;j++)
        if(s[j-poz+1]!=t[j])
            cout<<j-poz+1<<" ";
    return 0;
}