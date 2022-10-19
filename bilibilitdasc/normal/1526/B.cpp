#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int n;
void Q()
{
    cin>>n;
    if(n-(n%11)*111>=0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
int t;
int main()
{
    cin>>t;
    while(t--)
    Q();
    return 0;
}