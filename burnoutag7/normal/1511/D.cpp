#include<bits/stdc++.h>
using namespace std;

int n,k;
string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(char l='a';l<='a'+k-1;l++)for(char r=l;r<='a'+k-1;r++){
        s+=l;
        if(l!=r)s+=r;
    }
    while(n>=s.size()){
        n-=s.size();
        cout<<s;
    }
    cout<<s.substr(0,n);

    return 0;
}