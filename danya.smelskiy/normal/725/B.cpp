#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
string s;
unsigned long long num;
unsigned long long ans;
char c,a[100];
int k;
int main(){
    getline(cin,s);
    c=s[s.size()-1];
    if (c=='a') k=4;
    if (c=='b') k=5;
    if (c=='c') k=6;
    if (c=='d') k=3;
    if (c=='e') k=2;
    if (c=='f') k=1;
    for (int i=0;i<s.size()-1;++i)
        num=num*10+s[i]-'0';
    ans=(num-1)/4*12+(num-1)/4+(num-1)/4*3;
    num=(num-1)%4+1;
    if (num==1) ans+=k;
    if (num==2) ans+=7+k;
    if (num==3) ans+=k;
    if (num==4) ans+=7+k;

    cout<<ans;
}