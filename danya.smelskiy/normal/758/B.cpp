#include <bits/stdc++.h>
using namespace std;
string s,sk;
map<char,int> ss;
map<char,int> kol;

int main(){
    cin>>s;
    for (int i=1;i<=s.size();++i){
        if (s[i-1]!='!'){
            ss[s[i-1]]=i%4;
            if (ss[s[i-1]]==0) ss[s[i-1]]=4;
        }
    }
    sk="RBYG";
    for (int i=1;i<=s.size();++i){
        if (s[i-1]=='!'){
            for (int j=0;j<sk.size();++j){
                int x=ss[sk[j]];
                int y=i%4; if (y==0) y=4;
                if (x==y){
                    ++kol[sk[j]];
                    break;
                }
            }
        }
    }
    for (int i=0;i<sk.size();++i)
        cout<<kol[sk[i]]<<" ";
}