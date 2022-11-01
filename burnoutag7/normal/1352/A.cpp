#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            cnt+=s[i]!='0';
        }
        cout<<cnt<<endl;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0')cout<<s[i]+string(s.size()-i-1,'0')<<' ';
        }
        cout<<endl;
    }

    return 0;
}