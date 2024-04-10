#include <bits/stdc++.h>
using namespace std;

long long a,b,c,d,x,y;

int main(){
    cin>>a>>b>>c>>d>>x>>y;
    if (abs(a-c)%x==0 && abs(b-d)%y==0 && (abs(a-c)/x)%2==(abs(b-d)/y)%2) cout<<"YES";
    else cout<<"NO";
}