#include <bits/stdc++.h>
using namespace std;
const long long md=1000000007;
long long x,y,n;

int main(){
    cin>>x>>y>>n;
    n%=6;
    if (n==0) { if (x-y<0) cout<<(md+(x-y)%md)%md; else cout<<(x-y)%md;}
    else if (n==1) { if (x<0) cout<<(md+x)%md; else  cout<<x%md;}
    else if (n==2){ if (y<0) cout<<(md+y)%md; else  cout<<y%md;}
    else if (n==3){
     if ((y-x)<0) cout<<(md+(y-x)%md)%md;
     else cout<<(y-x)%md;
    }
    else if (n==4) {
    if (-x<0) cout<<(md-x)%md; else cout<<(-x)%md;
    }
    else if (n==5) { if (-y<0) cout<<(md-y)%md; else cout<<(-y)%md;}
}