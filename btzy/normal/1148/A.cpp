#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    unsigned long long a,b,c;
    cin>>a>>b>>c;
    cout<<c*2+min(a,b+1)+min(a+1,b)<<'\n';
}