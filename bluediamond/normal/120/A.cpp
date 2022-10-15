#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    string a;
    int b;
    cin>>a>>b;
    if(a=="front") {
        if(b==1)cout<<"L\n";
        else cout<<"R\n";
    }
    else {
        if(b==2)cout<<"L\n";
        else cout<<"R\n";
    }
    return 0;
}
/**
**/