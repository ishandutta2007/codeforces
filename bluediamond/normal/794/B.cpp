#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld n,h;
ld total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>h;
    total=h/2;
    total/=n;
    for(int i=1;i<n;i++){
        ld ht=sqrt((ld)2*h*total*(ld)i);
        cout<<fixed<<setprecision(6)<<ht<<" ";
    }
    return 0;
}