#include<bits/stdc++.h>
using namespace std;

string s;

void mian(){
    cin>>s>>s;
    sort(s.begin(),s.end());
    cout<<s<<'\n';
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