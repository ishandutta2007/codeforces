#include <bits/stdc++.h>
using namespace std;
string a;
bool t;
int main(){
    for (int i=1;i<=8;++i){
        cin>>a;
        for (int j=1;j<8;++j){
            if ((a[j]=='B' && a[j-1]=='W') || (a[j]=='W' && a[j-1]=='B')) continue;
            else t=true;
        }
    }
    if (t==true) cout<<"NO";
    else cout<<"YES";
}