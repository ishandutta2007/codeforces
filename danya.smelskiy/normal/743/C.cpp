#include <bits/stdc++.h>
using namespace std;
unsigned long long m;
long double n,k;
int main(){
    cin>>n;
    m=n;
    k=n/n+n/(n+1)+n/(n*(n+1));
    if (abs(2-k)<=0.00000001 && n*(n+1)!=n+1)
    cout<<m<<" "<<m+1<<" "<<m*(m+1);
    else cout<<-1;
}