#include <bits/stdc++.h>
using namespace std;
int n,x,posn,posp,nn,p;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x%2==0) {
            posp=i;
            ++p;
        } else {
            posn=i;
            ++nn;
        }
    }
    if (p<nn) cout<<posp;
    else cout<<posn;
}