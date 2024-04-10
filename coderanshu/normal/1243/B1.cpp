#include<bits/stdc++.h>
using namespace std;

int main()
{
    int j,count,n,z,m;
    string a;
    string b;
    char x[2],y[2];
    cin>>m;

    for(z=0;z<m;z++)
    {
        cin>>n;
        count=0;
        cin>>a>>b;
        for(j=0;j<n;j++)
        {
            if(count>2)
            {
                count=3;break;
            }
            if(a[j]!=b[j])
            {
                x[count]=a[j];y[count]=b[j];count++;
            }
        }
        if(count==0)cout<<"Yes\n";
        else if(count==2 && x[0]==x[1] && y[1]==y[0])cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}