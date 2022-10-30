#include <bits/stdc++.h>
using namespace std;
long long k,sum,kol[10000];
string s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k>>s;
    for (int i=(int)s.size()-1;i>=0;--i){
        ++kol[s[i]-'0'];
        sum+=s[i]-'0';
    }
    if (sum>=k) {
        cout<<"0";
        return 0;
    }
    k-=sum;
    long long ans=0;
    for (int i=0;i<10;++i) {
        long long z=kol[i]*(9-i);
        if (z>=k && i<9) {
            long long x=(k)/(9-i);
            if (k%(9-i)) ++x;
            ans+=x;
            break;
        }
        k-=z;
        ans+=kol[i];
    }
    cout<<ans;
}