#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,a[9],i,j;
    char x;
    cin>>k;
    for(i=0;i<9;i++)a[i]=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>x;
            if(x>=49 && x<=57)
            a[x-49]++;
        }
    }
    for(i=0;i<9;i++)
    {
        if(a[i]>2*k)
        {
            cout<<"NO";return 0;
        }
    }
    cout<<"YES";
    return 0;
}