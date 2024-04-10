#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a,b;
int c[123];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        while(a<=b){
           c[a]++;
           a++;
        }
    }
    
    // if(checK()){
        // cout<<"OK"<<endl;
    // }
    for(int i=1;i<=n;i++)
    {
        if(c[i]!=1)
        {
            cout<<i<<" "<<c[i]<<endl;
            exit(0);
        }
    }
    cout<<"OK"<<endl;
    return 0;
}