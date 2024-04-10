#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==0) {
        cout<<"a";
        return 0;
    }
    string res="";
    int last=0;
    char c='a';
    while (n) {
        if (last>n) {
            ++c;
            last=0;
        }
        res+=c;
        n-=last;
        ++last;
    }
    cout<<res;
}