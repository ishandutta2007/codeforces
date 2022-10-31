#include <bits/stdc++.h>
using namespace std;

long long n,m,k,x,y;
int main(){
    cin>>n>>m>>k;
    x=k/(2*m);
    if (k%(2*m)!=0) ++x;
    cout<<x<<" ";
    x=(k%(2*m));
    if (x==0) x=2*m;
    y=x/2;
    if (x%2!=0) ++y;
    cout<<y<<" ";
    if (x%2==0) cout<<"R";
    else cout<<"L";
}