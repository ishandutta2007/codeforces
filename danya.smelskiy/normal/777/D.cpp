#include <bits/stdc++.h>
using namespace std;
long long n;
string s[500005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s[i];
    }
    s[n].erase(s[n].begin());
    for (int i=n-1;i>0;--i){
        string sk="";
        sk+=s[i][1];
        if (sk>s[i+1] || s[i+1]=="" || s[i]=="#") s[i]="";
        else {
            long long z=s[i+1].size();
            bool t=false;
            if (s[i][1]<s[i+1][0]) t=true;
            for (int j=2;j<s[i].size();++j){
                if (j>z && t==false) break;
                if (j<=z && s[i][j]>s[i+1][j-1] && t==false) break;
                if (j<=z && s[i][j]<s[i+1][j-1]) t=true;
                sk+=s[i][j];
            }
            s[i]=sk;
        }
    }
    for (int i=1;i<=n;++i)
        cout<<"#"<<s[i]<<'\n';
}