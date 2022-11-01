#include <bits/stdc++.h>
using namespace std;

long long a,b,c;

int main(){
    cin>>a>>b>>c;
    if (a>b)swap(a,b); if (b>c) swap(b,c); if (a>b) swap(a,b);
    if (a==1 || (a==2 && b==2) || (a==3 && b==3 && c==3) || (a==2 && b==4 && c==4)) cout<<"YES";
    else cout<<"NO";
}