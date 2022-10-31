#include <bits/stdc++.h>
using namespace std;
long long n,maxim,minim=1000000000000,x,kolmin,kolmax;
long long a[500000];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x<minim){
            minim=x;
            kolmin=1;
        } else if (x==minim) ++kolmin;
        if (x>maxim){
            maxim=x;
            kolmax=1;
        } else if (x==maxim) kolmax++;
    }
    cout<<maxim-minim<<" ";
    if (maxim==minim) cout<<(n*(n-1))/2;
    else cout<<kolmin*kolmax;
}