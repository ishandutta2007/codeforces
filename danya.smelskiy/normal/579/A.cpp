#include <bits/stdc++.h>
using namespace std;
int n;
int recurs(int i){
    if (i==0) return 0;
    if (i==1) return 1;
    else return recurs(i/2)+recurs(i%2);
}
int main(){
    cin>>n;
    cout<<recurs(n/2)+recurs(n%2);
}