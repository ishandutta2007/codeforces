#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
map<long long,int> kol;
long long ans;
long long sum;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i=1;i<=s.size();++i){
        sum=0;
    for (int j=i;j<=s.size();++j) {
        sum+=s[j-1]-'0';
        ++kol[sum];
    }
    }
    for (int i=1;i<=s.size();++i){
        sum=0;
    for (int j=i;j<=s.size();++j) {
        sum+=s[j-1]-'0';
        if (sum>0 && n>0 && n%sum==0) ans+=kol[n/sum];
        else if (n==0) {
            if (sum==0) ans+=((int)s.size()*((int)s.size()+1))/2;
            else ans+=kol[0];
        }
    }
    }
    cout<<ans;
}