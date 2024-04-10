#include <bits/stdc++.h>
using namespace std;
string s,ss;
int n;
int kol[15],kol2[15];
int ans1,ans2;
bool t;
int main(){
    cin>>n;
    cin>>s;
    cin>>ss;
    for (int i=0;i<ss.size();++i){
        ++kol[ss[i]-'0'];
    }
    for (int i=0;i<=9;++i)
        kol2[i]=kol[i];
    for (int i=0;i<s.size();++i){
        t=false;
        for (int j=s[i]-'0'+1;j<=9;++j){
            if (kol[j]>0) {
                --kol[j];
                ++ans1;
                t=true;
                break;
            }
        }
        if (t) continue;
        for (int j=0;j<=9;++j)
        if (kol[j]>0) {
            --kol[j];
            break;
        }
    }
    for (int i=0;i<s.size();++i){
        t=false;
        for (int j=s[i]-'0';j<=9;++j)
        if (kol2[j]>0){
            --kol2[j];
            t=true;
            break;
        }
        if (t) continue;
        ++ans2;
        for (int j=0;j<=9;++j)
        if (kol2[j]>0){
            --kol2[j];
            break;
        }
    }
    cout<<ans2<<'\n'<<ans1;
}