#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c,a1,b1,c1;

int main(){
    cin>>n>>a>>a1>>b>>b1>>c>>c1;
    n-=a+b+c;
    for (;a<a1 && n>0;){
        a++;
        n--;
    }
    for (;b<b1 && n>0;){
        b++;
        n--;
    }
    for (;c<c1 && n>0;){
        c++;
        n--;
    }
    cout<<a<<" "<<b<<" "<<c;
}