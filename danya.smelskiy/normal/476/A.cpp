#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
int main(){
    cin>>n>>m;
    for (int i=0;i<=n;++i){
        if ((n-i)%2==0){
            x=(n-i)/2;
            if ((x+i)%m==0) {
                cout<<x+i;
                return 0;
            }
        }
    }
    cout<<"-1";
}