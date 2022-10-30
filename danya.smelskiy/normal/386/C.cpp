#include <bits/stdc++.h>
using namespace std;

string s;
int pos[100];
long long kol[100];
long long a[100];
int sz;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=1;i<=s.size();++i) {
        pos[s[i-1]-'a']=i;
        sz=0;
        for (int j=0;j<26;++j)
            if (pos[j]) a[++sz]=pos[j];
        sort(a+1,a+sz+1);
        for (int j=sz-1;j>=0;--j) {
            kol[sz-j]+=a[j+1]-a[j];
        }
    }
    for (int i=26;i>0;--i) if (kol[i]){
        cout<<i<<'\n';
        for (int j=1;j<=i;++j)
            cout<<kol[j]<<'\n';
        return 0;
    }
}