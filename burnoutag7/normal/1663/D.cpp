#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int x;
    cin>>s>>x;
    for(auto &c:s)if(c>='a'&&c<='z')c-='a'-'A';
    if(s=="ABC"){
        cout<<(x<2000?"Yes":"No");
    }else if(s=="ARC"){
        cout<<(x<2800?"Yes":"No");
    }else if(s=="AGC"){
        cout<<(x>=1200?"Yes":"No");
    }else{
        cout<<"No";
    }

    return 0;
}