#include <bits/stdc++.h>
using namespace std;
long long n,pos;
bool t;
int main(){
    cin>>n;
    pos=20000;
    for (int i=1;i<=n;++i){
        int x;
        string s;
        cin>>x>>s;
        if (s=="South") pos-=x;
        else if (s=="North") pos+=x;
        else if (pos==20000 || pos==0) t=true;
        if (pos>20000 || pos<0) {
            t=true;
        }
    }
    if (pos!=20000 || t==true) cout<<"NO";
    else cout<<"YES";
}