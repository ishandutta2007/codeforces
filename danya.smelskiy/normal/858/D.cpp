#include <bits/stdc++.h>
using namespace std;
int n;
string s[70005];
map<string,int> kol;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        string last;
        for (int j=0;j<9;++j) {
            last="";
            for (int k=j;k<9;++k){
                last+=s[i][k];
                int z=kol[last];
                if (z!=i && z!=0) kol[last]=-2;
                else kol[last]=i;
            }
        }
    }
    string res,last;
    for (int i=1;i<=n;++i) {
        int mn=9;
        res=s[i];
        last="";
        for (int j=0;j<9;++j) {
            last="";
            for (int k=j;k<9 && k-j+1<mn;++k) {
                last+=s[i][k];
                if (kol[last]==i) {
                    mn=k-j+1;
                    res=last;
                    break;
                }
            }
        }
        cout<<res<<'\n';
    }
}
////