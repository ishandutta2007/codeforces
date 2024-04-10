#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<string,bool> used;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        if (used[s]==false) {
            cout<<"NO"<<'\n';
            used[s]=true;
        } else cout<<"YES"<<'\n';
    }
}