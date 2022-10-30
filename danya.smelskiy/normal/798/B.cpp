#include <bits/stdc++.h>
using namespace std;
int n;
string s[100];
map<pair<int,string>,pair<bool,int> > used;
inline int chek(string x){
    int res=0;
    for (int i=1;i<=n;++i){
        if (used[make_pair(i,x)].first==false) return -1;
        res+=used[make_pair(i,x)].second;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s[i];
        used[make_pair(i,s[i])]=make_pair(true,0);
        for (int j=1;j<s[i].size();++j){
            string sk="";
            for (int z=j+1;z<=s[i].size();++z)
                sk+=s[i][z-1];
            for (int z=1;z<=j;++z)
                sk+=s[i][z-1];
            if (used[make_pair(i,sk)].first==true) {
                used[make_pair(i,sk)].second=min(used[make_pair(i,sk)].second,j);
            } else {
                used[make_pair(i,sk)]=make_pair(true,j);
            }
        }
    }
    bool t=false;
    int ans=1e9;
    for (int i=1;i<=s[1].size();++i){
        string sk="";
        for (int j=i+1;j<=s[1].size();++j)
            sk+=s[1][j-1];
        for (int j=1;j<=i;++j)
            sk+=s[1][j-1];
        int r=chek(sk);
        if (r!=-1) {
            t=true;
            ans=min(ans,r);
        }
    }
    if (t==false) ans=-1;
    cout<<ans;
}