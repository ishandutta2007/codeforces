#include<bits/stdc++.h>
using namespace std;

long long a,b,c;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c;
    cout<<c*2+min(a,b)*2+(a!=b)<<endl;

    return 0;
}