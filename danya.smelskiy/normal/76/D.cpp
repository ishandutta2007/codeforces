#include <bits/stdc++.h>
using namespace std;
unsigned long long a,b;
int main(){
    cin>>a>>b;
    unsigned long long x=(a-b)/(unsigned long long)2;
    unsigned long long y=x+b;
    if (x+y==a && (x^y)==b) cout<<x<<" "<<y;
    else cout<<"-1";
}