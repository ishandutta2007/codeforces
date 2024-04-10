#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    double k=1.0,q=1.0*(b-a)*(d-c)/b/d;
    k=1.0*a/b*1/(1-q);
    cout<<k;
}