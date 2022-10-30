#include <bits/stdc++.h>
using namespace std;
long double a,b,c,d,f,s;
int main(){
    cin>>a>>b>>c>>d;
    if (c!=0) f=max((3*a)/10,a-(a*c)/250);
    else f=a;
    if (d!=0) s=max((3*b)/10,b-(b*d)/250);
    else s=b;
    if (f==s) cout<<"Tie";
    else if (f>s) cout<<"Misha";
    else cout<<"Vasya";
}