#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
string s,a[100001],ss;
int ans[10000];
int maxkol;
bool t;
int j;
int main(){
    cin>>s;
    for (int i=0;i<s.size();++i){
        if (s[i]>='a' && s[i]<='z' && t==false){
            t=true;
            ++j;
        } else if ((s[i]>='0' && s[i]<='9') || s[i]=='.') {a[j]=a[j]+s[i]; t=false;}
    }
    for (int i=1;i<=j;++i){
        s=a[i];
        //  
        int kol=0;
        for (int j=0;j<s.size();++j)
            if (s[j]=='.') ++kol;
            ++kol;
        if (s[s.size()-3]!='.') ++kol;
        if (kol>maxkol) maxkol=kol;
        for (int j=0;j<s.size();++j){
            if (s[j]=='.'){
            //    cout<<ss<<endl;
                ans[kol]+=atoi(ss.c_str());
                --kol;
                ss="";
            } else ss=ss+s[j];
        }
        ans[kol]+=atoi(ss.c_str());
        ss="";
    }
    if (ans[1]>=100){
        ans[2]+=ans[1]/100;
        ans[1]%=100;
        if (maxkol==1) ++maxkol;
        }
    if (ans[2]>=1000){
        ans[3]+=ans[2]/1000;
        ans[2]%=1000;
        if (maxkol==2) ++maxkol;
    }
    if (ans[3]>=1000){
        ans[4]+=ans[3]/1000;
        ans[3]%=1000;
        if (maxkol==3) ++maxkol;
    }
    if (ans[4]>=1000){
        ans[5]+=ans[4]/1000;
        ans[4]%=1000;
        ++maxkol;
    }
    for (int i=maxkol;i>1;--i){
        if (i==maxkol) cout<<ans[i]; else {
            if (ans[i]<100) cout<<"0";
            if (ans[i]<10) cout<<"0";
            cout<<ans[i];
        }
        if (i>2) cout<<".";}
    if (ans[1]>0){
        cout<<".";
        if (ans[1]<10) cout<<"0";
        cout<<ans[1];
    }
}