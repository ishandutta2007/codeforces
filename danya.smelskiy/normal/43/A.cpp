#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
string s,ss;
map<string,int> a;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        ++a[s];
        if (a[s]>ans) { ans=a[s]; ss=s;}
    }
    cout<<ss;
}