#include <bits/stdc++.h>
using namespace std;

string s;
int ans;

int main(){
    cin>>s;
    int l=0;
    int r=s.size()-1;
    while (l<r) {
            if( s[l]!=s[r]) ++ans;
        ++l;
        --r;
    }
    if (ans>1 || (ans==0 && (s.size()%2==0))) cout<<"NO";
    else cout<<"YES";
}