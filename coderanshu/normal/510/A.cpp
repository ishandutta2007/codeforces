#include<bits/stdc++.h>
using namespace std;
int main()
{
 
    int n,m,j;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(j=0;j<m;j++)
                cout<<"#";
        }
        else 
        {
            if((i+1)%4==0)
            cout<<"#";
            else cout<<".";
            for(j=1;j<m-1;j++)
            cout<<".";
            if((i+1)%4==0)
            cout<<".";
            else cout<<"#";
        }
        cout<<"\n";
    }
   
    return 0; 
}