#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
    cin>>a>>b;
    if (b%2==0) swap(a,b);
    if (a%2==0){
        cout<<a/2*b;
    } else {
        cout<<a/2*b+b/2;
    }
}