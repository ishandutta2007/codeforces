#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    if (a==1 && b==1 && c==1) cout<<3;
    else if (a==1 && b!=1 && c!=1) cout<<max(b*c,(1+b)*c);
    else if (a!=1 && b!=1 && c==1) cout<<max(a*b,(1+b)*a);
    else if (a==1 && c==1 && b!=1) cout<<2+b;
    else if (b==1 && a!=1 && c!=1) cout<<max((1+a)*c,(1+c)*a);
    else if (a==1 && b==1 && c!=1) cout<<2*c;
    else if (b==1 && c==1 && a!=1) cout<<2*a;
    else cout<<a*b*c;
}