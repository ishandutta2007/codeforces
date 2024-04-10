#include <bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main(){
    cin>>a>>b>>c;
    if (c>=0){
        ans=(b+c)%a;
        if (ans==0) cout<<a;
        else cout<<ans;
    } else {
        c=abs(c);
        c%=a;
        c=a-c;
     //   cout<<c<<endl;
        ans=(b+c)%a;
        if (ans==0) cout<<a;
        else cout<<ans;
    }
}