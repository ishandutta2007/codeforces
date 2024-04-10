#include <bits/stdc++.h>
using namespace std;
long long n,m,j;
string s;
string st[100000];
long long per(string s){
    long long sum=0;
    for (int jj=1;jj<=s.size();++jj){
            sum*=10;
            sum+=(s[jj-1]-'0');
    }
    return sum;
}
int main(){
    cin>>n;
    while (n>0){
            m=n;
            s="";
            while (m>0){
                if (m%10==0) s="0"+s;
                else s="1"+s;
                m/=10;
            }
            ++j; st[j]=s;
            n-=(per(s));
    }
    cout<<j<<'\n';
    for (int i=1;i<=j;++i){
    cout<<st[i]<<" ";}
}