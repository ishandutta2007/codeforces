#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    int a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d;
    e=a*d;f=b*c;
    if(f>e){g=f;f=e;e=g;}
    for(h=1;h<=e;h++)
        if(e%h==0&&f%h==0)g=h;
    e/=g;f/=g;
    cout<<(e-f)<<"/"<<e;
}