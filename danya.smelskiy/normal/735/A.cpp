#include <bits/stdc++.h>
using namespace std;
long long n,m,f,ss;
string s;
int main(){
    cin>>n>>m;
    cin>>s;
    for (int i=0;i<s.size();++i){
        if (s[i]=='G') f=i;
        if (s[i]=='T') ss=i;
    }
    if (ss<f) swap(ss,f);
    if ((ss-f)%m!=0){
        cout<<"NO";
        return 0;
    }
    while (f!=ss){
        if (s[f]=='#'){
            cout<<"NO";
            return 0;
        }
        f+=m;
    }
    cout<<"YES";
}