#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<string,bool> used;
map<string,int> k;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        if (used[s]==false){
            cout<<"OK"<<'\n';
            used[s]=true;
            ++k[s];
        } else {
            cout<<s<<k[s]<<'\n';
            ++k[s];
        }
    }
}