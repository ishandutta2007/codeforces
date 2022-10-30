#include <bits/stdc++.h>
using namespace std;
int n,k,l,c,d,p,nl,np;
int main(){
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    cout<<min((c*d)/n,min((k*l)/(n*nl),p/(np*n)));
}