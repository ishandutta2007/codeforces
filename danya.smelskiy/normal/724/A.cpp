#include <bits/stdc++.h>
using namespace std;
string s,s1;
int one,two;
int last,a[30],b[30];
int main(){
    a[1]=31; a[2]=28; a[3]=31; a[4]=30; a[5]=31; a[6]=30; a[7]=31; a[8]=31; a[9]=30; a[10]=31; a[11]=30; a[12]=31;
    cin>>s>>s1;
    if (s=="monday") one=1;
    if (s=="tuesday") one=2;
    if (s=="wednesday") one=3;
    if (s=="thursday") one=4;
    if (s=="friday") one=5;
    if (s=="saturday") one=6;
    if (s=="sunday") one=7;
    if (s1=="monday") two=1;
    if (s1=="tuesday") two=2;
    if (s1=="wednesday") two=3;
    if (s1=="thursday") two=4;
    if (s1=="friday") two=5;
    if (s1=="saturday") two=6;
    if (s1=="sunday") two=7;
    for (int k=1;k<=7;++k){
    last=k;
    for (int i=1;i<=12;++i){
        b[i]=last;
        if (b[i]==two && b[i-1]==one) {
            cout<<"YES";
            return 0;
        }
        last=(last+a[i])%7;
        if (last==0) last=7;
    }
    }
    cout<<"NO";
}