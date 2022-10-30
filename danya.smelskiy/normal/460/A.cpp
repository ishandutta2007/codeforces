#include <bits/stdc++.h>
using namespace std;
int a,b; int ans,k;
int main(){
    cin>>a>>b;
    if (b>a) cout<<a; else {
        while (a>0){
            --a;
            ++k;
            if (k%b==0) ++a;
        }
        cout<<k;
    }
}