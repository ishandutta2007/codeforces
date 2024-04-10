#include <bits/stdc++.h>
using namespace std;

string a,b;
string ans;
int kol[100];
int kol2[100];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    for (int i=0;i<a.size();++i)
        ++kol[a[i]-'0'];
    if (b.size()>a.size()) {
        string res="";
        for (int i=9;i>=0;--i)
            while (kol[i]--) res+=char(i+'0');
        cout<<res;
        return 0;
    }
    for (int i=0;i<=b.size();++i) {
        for (int j=0;j<10;++j)
            kol2[j]=kol[j];
        bool t=false;
        string res="";
        for (int k=1;k<=i;++k) {
            res+=b[k-1];
            kol2[b[k-1]-'0']--;
            if (kol2[b[k-1]-'0']<0) {
                t=true;
                break;
            }
        }
        if (t) continue;
        if (i==b.size()) {
            ans=max(ans,res);
            continue;
        }
        int x=b[i]-'0';
        t=false;
        int c;
        for (int j=9;j>=0;--j)
            if (kol2[j] && j<x) {
                --kol2[j];
                t=true;
                c=j;
                break;
            }
        if (t==false) continue;
        if (c==0 && i==0) continue;
        res+=char(c+'0');
        for (int i=9;i>=0;--i)
            while (kol2[i]--) res+=char(i+'0');
        ans=max(ans,res);
    }
    cout<<ans;
}