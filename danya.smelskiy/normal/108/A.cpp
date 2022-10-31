#include <bits/stdc++.h>
using namespace std;
string s;
long long x;
int main(){
    cin>>s;
    x=((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0');
    while (true){
        ++x;
        if (x==24*60) x=0;
        long long y=x/60;
        long long z=x%60;
        long long a=y/10;
        long long b=y%10;
        long long c=z/10;
        long long d=z%10;
        if (a==d && b==c){
            cout<<a<<b<<":"<<c<<d;
            return 0;
        }
    }
}