#include <bits/stdc++.h>
using namespace std;
string s;
int kol[10000],m;
int main(){
    cin>>m;
    cin>>s;
    if (s.size()%4!=0){
        cout<<"===";
        return 0;
    }
    int n=(s.size())/4;
    for (int i=0;i<s.size();++i){
        if (s[i]=='?') continue;
        ++kol[s[i]];
        if (kol[s[i]]>n){
            cout<<"===";
            return 0;
        }
    }
    for (int i=0;i<s.size();++i){
        if (s[i]=='?'){
            if (kol['A']<n){
                cout<<"A";
                ++kol['A'];
            }
            else if (kol['C']<n){
                cout<<"C";
                ++kol['C'];
            } else if (kol['G']<n){
                cout<<"G";
                ++kol['G'];
            } else if (kol['T']<n){
                cout<<"T";
                ++kol['T'];
            }
        } else cout<<s[i];
    }
}