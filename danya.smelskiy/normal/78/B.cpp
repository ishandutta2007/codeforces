#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    s="GBIV";
    cout<<"ROY";
    int last=0;
    n-=3;
    for (int i=1;i<=n;++i) {
        cout<<s[last];
        last=(last+1)%4;
    }
}