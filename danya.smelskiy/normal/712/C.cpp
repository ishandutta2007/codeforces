#include <bits/stdc++.h>

using namespace std;
long long x,y,a,b,c,j,ans;
int main(){
    cin>>x>>y;
    a=y; b=y; c=y;
    while (a!=x || b!=x || c!=x){
        if (b<a) swap(a,b); if (c<b) swap(c,b); if (b<a) swap(b,a);
        a=min(x,b+c-1);
        ++ans;
    }
    cout<<ans;
}