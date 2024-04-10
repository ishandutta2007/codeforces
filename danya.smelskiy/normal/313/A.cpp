#include <bits/stdc++.h>
using namespace std;
int x;
int main(){
    cin>>x;
    if (x>0) cout<<x;
    else {
        int k=x/100;
        cout<<max(k*10+x%10,k*10+(x/10)%10);
    }
}