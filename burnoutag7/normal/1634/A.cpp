#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s;
    t=s;
    reverse(t.begin(),t.end());
    bool palin=s==t;
    if(!k||palin)cout<<"1\n";
    else cout<<"2\n";
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