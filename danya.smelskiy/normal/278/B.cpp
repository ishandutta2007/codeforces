#include <bits/stdc++.h>
using namespace std;
string s[2000];
long long n;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>s[i];
    for (int i=1;i<=26;++i){
        char c=char('a'+i-1);
        bool tt=false;
        for (int j=1;j<=n;++j){
            for (int z=0;z<s[j].size();++z)
                if (s[j][z]==c){
                    tt=true;
                    break;
                }
            if (tt==true) break;
        }
        if (tt==false) {
            cout<<c;
            return 0 ;
        }
    }
    for (int i=1;i<=26;++i){
        for (int j=1;j<=26;++j){
            char ss=char('a'+i-1);
            char sk=char('a'+j-1);
            bool tt=false;
            for (int k=1;k<=n;++k){
                for (int z=1;z<s[k].size();++z)
            if (s[k][z-1]==ss && s[k][z]==sk){
                tt=true;
                break;
            }
            if (tt==true) break;
            }
            if (tt==false){
                cout<<ss<<sk;
                return 0;
            }
        }
    }
}