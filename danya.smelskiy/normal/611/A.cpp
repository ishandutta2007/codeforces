#include <bits/stdc++.h>
using namespace std;
string s,s1;
int a[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n,ans;
int main(){
    cin>>n>>s>>s1;
    if (s1=="week"){
        int kol=5;
        for (int i=1;i<=366;++i){
            if (kol==n) ++ans;
            ++kol;
            if (kol==8) kol=1;
        }
        cout<<ans;
        return 0;
    }
    for (int i=0;i<12;++i)
        if (a[i]>=n) ++ans;
    cout<<ans;
}