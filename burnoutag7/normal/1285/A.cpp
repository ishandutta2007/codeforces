#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int cl,cr;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='L')cl--;
        if(s[i]=='R')cr++;
    }
    cout<<cr-cl+1<<endl;

    return 0;
}