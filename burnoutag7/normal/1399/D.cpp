#include<bits/stdc++.h>
using namespace std;

int n,cnt;
string s;
set<int> t[2];
vector<int> v;

void mian(){
    cin>>n>>s;
    cnt=0;
    t[0].clear();
    t[1].clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        if(t[s[i]-'0'].empty()){
            t[s[i]-'0'^1].insert(v[i]=++cnt);
        }else{
            t[s[i]-'0'^1].insert(v[i]=*t[s[i]-'0'].begin());
            t[s[i]-'0'].erase(t[s[i]-'0'].begin());
        }
    }
    cout<<cnt<<'\n';
    for(int &x:v)cout<<x<<' ';
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}