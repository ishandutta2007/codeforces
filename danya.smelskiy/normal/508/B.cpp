#include <bits/stdc++.h>
using namespace std;
string s;
bool t;
int x;
int main(){
       cin>>s;
       for (int i=0;i<s.size();++i){
         x=s[i]-'0';
         if (x%2==0) t=true;
         if (x%2==0 && x<s[s.size()-1]-'0'){
            swap(s[i],s[s.size()-1]);
            cout<<s;
            return 0;
         }
       }
        if (t==false){
            cout<<"-1";
            return 0;
        }
        for (int i=s.size()-2;i>=0;--i){
            x=s[i]-'0';
            if (x%2==0 && x>=(s[s.size()-1]-'0')){
                swap(s[i],s[s.size()-1]);
                cout<<s;
                return 0;
            }
        }
}