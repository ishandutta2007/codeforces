#include <bits/stdc++.h>
using namespace std;
int n;
int i=1;
int main(){
    cin>>n;
    while (i*5<n){
    n-=i*5;
    i*=2;
    }
    if (n<=i) cout<<"Sheldon";
    else if (n<=i*2) cout<<"Leonard";
    else if (n<=i*3) cout<<"Penny";
    else if (n<=i*4) cout<<"Rajesh";
    else cout<<"Howard";
}