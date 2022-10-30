#include <bits/stdc++.h>
using namespace std;
long long a,b,c,x;
int main(){
    cin>>a>>b>>c;
    if (c>0 && b<a){
        cout<<"NO";
        return 0;
    }
    if (c<0 && b>a) {
        cout<<"NO";
        return 0;
    }
    if (c==0 && b!=a){
        cout<<"NO";
        return 0;
    } else if (c==0 && b==a) {
        cout<<"YES";
        return 0;
    }
    x=abs(b-a);
    if (x%c==0) cout<<"YES";
    else cout<<"NO";
}