#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    int ans=s/n;
    if(s%n) ans++;
    cout<<ans<<endl;
}