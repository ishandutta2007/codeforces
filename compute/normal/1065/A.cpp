#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long s,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s>>a>>b>>c;
        long long ans=s/c+s/c/a*b;
        cout<<ans<<endl;
    }
}