#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    for (int i=1;i<=10000;++i){
        int nn=n*i;
        if ((nn%10)==m || nn%10==0) {
            cout<<i;
            return 0;
        }
    }
}