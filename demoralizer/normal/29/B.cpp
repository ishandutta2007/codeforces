#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int l,d,v,g,r;
    cin>>l>>d>>v>>g>>r;
    double a;
    double x=1.0*d/v;
    while(x>=(g+r))x-=(g+r);
    if(x<g)x=0;
    else x=r+g-x;
    a=x+1.0*l/v;
    cout<<setprecision(9)<<a;
}