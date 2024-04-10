#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> qq;
long long ans;
inline pair<long long,long long> solve(int l,int r){
    long long x=0,y=s[l]-'0';
    for (int i=l+2;i<=r;i+=2) {
        if (s[i-1]=='*') y*=(long long)(s[i]-'0');
        else {
            x+=y;
            y=s[i]-'0';
        }
    }
    return make_pair(x,y);
}
inline long long solve2(pair<long long,long long> x,int l){
    for (int i=l;i<s.size();i+=2) {
        if (s[i-1]=='*') x.second*=(long long)(s[i]-'0');
        else {
            x.first+=x.second;
            x.second=s[i]-'0';
        }
    }
    return x.first+x.second;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    s="1*"+s;
    s+="*1";
    for (int i=0;i<s.size();++i) {
        if (s[i]=='*') qq.push_back(i);
    }
    for (int i=0;i<qq.size();++i)
    for (int j=i+1;j<qq.size();++j){
        pair<long long,long long> x=solve(0,qq[i]-1);
        pair<long long,long long> y=solve(qq[i]+1,qq[j]-1);
        x.second*=(y.first+y.second);
        long long res=solve2(x,qq[j]+1);
        ans=max(ans,res);
    }
    cout<<ans;
}