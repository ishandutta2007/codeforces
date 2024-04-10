#include<bits/stdc++.h>
using namespace std;

int n,c1;
string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)c1+=s[i]=='1';
    if(c1*2==n){
        cout<<2<<endl<<s.substr(0,s.size()-1)<<' '<<s.back()<<endl;
    }else{
        cout<<1<<endl<<s<<endl;
    }

    return 0;
}