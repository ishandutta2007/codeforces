#include <bits/stdc++.h>
using namespace std;
string s;
int ans;

void recurs(string ss){
    if (ss.size()<s.size()) ++ans;
    if (ss.size()==s.size()){
        //cout<<ss<<endl;
        if (ss<=s) ++ans;
        return;
    }
    recurs(ss+'4');
    recurs(ss+'7');
}
int main(){
    cin>>s;
    recurs("");
    cout<<ans-1;
}