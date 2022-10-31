#include <bits/stdc++.h>
using namespace std;
string s[10001][3];
string ss,sk;
int n;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s[0][1]>>s[0][2];
    cin>>n;
    cout<<s[0][1]<<" "<<s[0][2]<<'\n';
    for (int i=1;i<=n;++i){
        cin>>ss>>sk;
        if (ss==s[0][1]) s[0][1]=sk;
        else s[0][2]=sk;
        cout<<s[0][1]<<" "<<s[0][2]<<'\n';
    }

}