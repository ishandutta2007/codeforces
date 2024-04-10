#include <bits/stdc++.h>
using namespace std;
long long a,b,n;
int main(){
    cin>>a>>b>>n;
    if (n<abs(a)+abs(b)||((n-abs(a)-abs(b))%2!=0)) cout<<"No";
    else cout<<"Yes";

}