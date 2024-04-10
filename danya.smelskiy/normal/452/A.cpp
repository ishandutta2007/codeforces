#include <bits/stdc++.h>
using namespace std;
string ss,s[9];
bool t;
int main(){
    int n;
    cin>>n;
    s[1]="vaporeon"; s[2]="jolteon"; s[3]="flareon"; s[4]="espeon"; s[5]="umbreon"; s[6]="leafeon"; s[7]="glaceon"; s[8]="sylveon";
    cin>>ss;
    for (int i=1;i<=8;++i){
        if (s[i].size()==ss.size()){
                t=false;
            for (int j=1;j<=ss.size();++j)
            if (ss[j]!='.' && ss[j]!=s[i][j]){
                t=true;
                break;
            }
            if (t==false) {
                cout<<s[i];
                return 0;
            }
        }
    }
}