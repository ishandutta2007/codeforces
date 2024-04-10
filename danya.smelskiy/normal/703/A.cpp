#include <bits/stdc++.h>
using namespace std;
int n,x,y,f,s;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
    cin>>x>>y;
    if (x>y) ++f;
    else if (x<y) ++s;
    }
    if (f==s) cout<<"Friendship is magic!^^";
    else if (f<s) cout<<"Chris";
    else cout<<"Mishka";
}