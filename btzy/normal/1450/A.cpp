#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct!=tc;++ct){
        int n;
        string str;
        cin>>n;
        cin>>str;
        sort(str.begin(),str.end());
        cout<<str<<'\n';
    }
}