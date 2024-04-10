#include <bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
    cin>>a>>b>>c;
    int x=(a+b+c)/5;
    if ((a+b+c)%5>0) ++x;
    cin>>a>>b>>c;
    int y=(a+b+c)/10;
    if ((a+b+c)%10>0) ++y;
    cin>>n;
    if (x+y<=n) cout<<"YES";
    else cout<<"NO";
}