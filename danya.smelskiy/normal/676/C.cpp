#include <bits/stdc++.h>
using namespace std;
int n,k,l1,l2,kol1,kol2,ans,ans1;
string s;
int kola,kolb;
int main(){
    cin>>n>>k>>s;
    l1=0;    l2=0;    kol1=0;    kol2=0;
    kola=0;
    kolb=0;
    if (s[0]=='a') ++kola;
    else ++kolb;
    ans1=1;
    for (int i=1;i<s.size();++i){
        if (s[i]=='a') {
            ++kola;
            kolb=0;
        } else {
            ++kolb;
            kola=0;
        }
        ans1=max(ans1,max(kola,kolb));
    }
    if (k==0){
        cout<<ans1;
        return 0;
    }
    for (int i=0;i<s.size();++i){
        if (s[i]=='a') ++kol2;
        else ++kol1;
        if (kol2>k){
            for (int j=l2;j<=i;++j)
            if (s[j]=='a'){
                l2=j+1;
                --kol2;
                break;
            }
        }
        if (kol1>k){
            for (int j=l1;j<=i;++j)
            if (s[j]=='b'){
                l1=j+1;
                --kol1;
                break;
            }
        }
        ans=max(ans,max(i-l1+1,i-l2+1));
    }
    cout<<max(ans1,ans);
}