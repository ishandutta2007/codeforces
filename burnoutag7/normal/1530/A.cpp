#include<bits/stdc++.h>
using namespace std;

void mian(){
    string s;
    cin>>s;
    cout<<*max_element(s.begin(),s.end())-'0'<<'\n';
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