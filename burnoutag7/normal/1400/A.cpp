#include<bits/stdc++.h>
using namespace std;

int n;
string s;

void mian(){
    cin>>n;
    cin>>s;
    while(n--)cout<<s[s.size()>>1];
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}