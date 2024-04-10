#include <bits/stdc++.h>
using namespace std;

map<char,int> m;
string s;
int ans;
int main(){
    m['Q']=9; m['q']=-9;
    m['R']=5; m['r']=-5;
    m['B']=3; m['b']=-3;
    m['N']=3; m['n']=-3;
    m['P']=1; m['p']=-1;
    for (int i=1;i<=8;++i){
        cin>>s;
        for (int j=0;j<8;++j){
            ans+=m[s[j]];
        }
    }
    if (ans>0) cout<<"White";
    else if (ans<0) cout<<"Black";
    else cout<<"Draw";
}