#include <bits/stdc++.h>
using namespace std;
string s,s2;
vector<int> v;
long long fs,ft,ss,st;
long long sum;
int main(){
    cin>>s>>s2;
    for (int i=0;i<s.size();++i){
        fs=fs*10+(s[i]-'0');
        if (s[i]!='0') ft=ft*10+(s[i]-'0');
    }
    for (int i=0;i<s2.size();++i){
        ss=ss*10+(s2[i]-'0');
        if (s2[i]!='0') st=st*10+(s2[i]-'0');
    }
    sum=fs+ss;
    while (sum>0){
            if (sum%10!=0)
        v.push_back(sum%10);
        sum/=10;
    }
    for (int i=v.size()-1;i>=0;--i)
        sum=sum*10+v[i];
   // cout<<sum<<endl;
    if (ft+st==sum) cout<<"YES";
    else cout<<"NO";
}