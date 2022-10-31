#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (n==1 && m==0){
        cout<<"0";
        return 0;
    }
    if (m==0) {
        cout<<"No solution";
        return 0;
    }
    cout<<m;
    n--;
    while (n--) {
        cout<<"0";
    }
}