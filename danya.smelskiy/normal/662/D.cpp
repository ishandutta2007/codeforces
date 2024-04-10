#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        string ss="";
        for (int i=4;i<s.size();++i)
            ss+=s[i];
        s=ss;
        long long x=0;
        for (int i=0;i<s.size();++i)
            x=(x*10ll+(s[i]-'0'));
        long long last=1;
        long long sum=0;
        for (int i=1;i<s.size();++i) {
            last*=10;
            sum+=last;
        }
        last*=10;
        sum+=1989;
        long long res=x;
        while (res<sum) res+=last;
        cout<<res<<'\n';
    }
}