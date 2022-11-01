#include<bits/stdc++.h>
using namespace std;

long double d;
int n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    do{
        d+=(long double)1/n;
        --n;
    }while(n);
    cout<<fixed<<setprecision(10)<<d<<endl;

    return 0;
}