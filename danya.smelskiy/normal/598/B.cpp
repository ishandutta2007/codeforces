#include <bits/stdc++.h>
using namespace std;
string s;
long long x,y,z,m;
int main(){
    cin>>s>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y>>z;
        long long k=(y-x)+1;
        z%=k;
        string s1=s;
        for (int i=x;i<=y;++i){
            if (i+z<=y) s1[i+z-1]=s[i-1];
            else s1[x+(i+z)%y-2]=s[i-1];
        }
        s=s1;
    }
    cout<<s;
}