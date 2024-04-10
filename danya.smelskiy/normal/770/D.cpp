#include <bits/stdc++.h>
using namespace std;

string s;
int n,now,d;
int l;
char a[1001][1001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i=0;i<s.size();++i){
        if (s[i]=='[') ++now;
        else --now;
        d=max(d,now);
    }
    int u=1;
    d=d*2+1;
    l=1;
    for (int i=0;i<n;++i){
        a[u][l]='+';
        a[d][l]='+';
        if (s[i]=='['){
            a[u][l+1]='-';
            a[d][l+1]='-';
        } else {
            a[u][l-1]='-';
            a[d][l-1]='-';
        }
        for (int j=u+1;j<d;++j)
            a[j][l]='|';
        if (i==n-1) break;
        if (s[i]=='[' && s[i+1]==']') {
            l+=4;
        } else if (s[i]=='[' && s[i+1]=='[') {
            l++;
            u++;
            d--;
        } else if (s[i]==']' && s[i+1]==']') {
            l++;
            u--;
            d++;
        } else {
            l++;
        }
    }
    for (int i=1;i<=d;++i){
        for (int j=1;j<=l;++j)
            if (!a[i][j]) cout<<" ";
            else cout<<a[i][j];
        cout<<'\n';
    }
}