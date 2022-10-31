#include <bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main(){
    cin>>a>>b>>c;
    ans=a+b+c;
    ans=min(ans,a+a+b+b);
    ans=min(ans,a+a+c+c);
    ans=min(ans,b+b+c+c);
    cout<<ans;
}