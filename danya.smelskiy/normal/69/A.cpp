#include <bits/stdc++.h>
using namespace std;
int n,x,y,z;
long long a,b,c;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y>>z;
        a+=x; b+=y; c+=z;
    }
    if (a==0 && b==0 && c==0) cout<<"YES";
    else cout<<"NO";
}