#include <bits/stdc++.h>
using namespace std;
int n,x;
int main(){
    cin>>n;
    x=n/2;
    while (true){
        if ((x%2==0 || x%3==0) && ((n-x)%2==0 || (n-x)%3==0)) { cout<<x<<" "<<n-x; return 0;}
        --x;
    }
}