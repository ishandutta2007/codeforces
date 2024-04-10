#include<bits/stdc++.h>
using namespace std;

int m,n;
vector<int> essay;
int val[300005];
int len[300005];
map<string,int> mp;int mpcnt;
vector<int> g[300005];

void add(string &s){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a')s[i]-='a'-'A';
        cnt+=s[i]=='R';
    }
    if(mp.find(s)!=mp.end())return;
    mp[s]=++mpcnt;
    len[mpcnt]=s.size();
    val[mpcnt]=cnt;
}

void dfs(int x){
    for(int &y:g[x]){
        if(val[y]>val[x]||(val[y]==val[x]&&len[y]>len[x])){
            val[y]=val[x];
            len[y]=len[x];
            dfs(y);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        add(s);
        essay.push_back(mp[s]);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        string s,t;
        cin>>s>>t;
        add(s);add(t);
        g[mp[t]].push_back(mp[s]);
    }
    vector<int> v(mpcnt);
    iota(v.begin(),v.end(),1);
    sort(v.begin(),v.end(),[](int a,int b){
        if(val[a]!=val[b])return val[a]<val[b];
        else return len[a]<len[b];
    });
    for(int i=0;i<mpcnt;i++){
        dfs(v[i]);
    }
    long long ansv=0,ansl=0;
    for(int i=0;i<m;i++){
        ansv+=val[essay[i]];
        ansl+=len[essay[i]];
    }
    cout<<ansv<<' '<<ansl<<endl;

    return 0;
}