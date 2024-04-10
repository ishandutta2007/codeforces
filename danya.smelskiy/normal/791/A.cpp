#include <bits/stdc++.h>
using namespace std;


long long n,m;
int main(){
    cin>>n>>m;
    for (int i=0;i<100;++i){
        if (n>m) {
            cout<<i;
            return 0;
        }
        n*=3;
        m+=m;
    }
}