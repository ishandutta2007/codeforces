#include <bits/stdc++.h>
using namespace std;
int n;
bool t;
void recurs(int i){
    if (i!=0) if (n%i==0) t=true;
    if (t==false && i<=n){
        recurs(i*10+7);
        recurs(i*10+4);
    }
}
int main(){
    cin>>n;
    recurs(0);
    if (t==true) cout<<"YES";
    else cout<<"NO";
}