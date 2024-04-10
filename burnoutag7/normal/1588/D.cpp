#include<bits/stdc++.h>
using namespace std;

const int V=53248;

int n,len[V],nxt[V];
string S[10],ch;
vector<int> g[V],oc[V];

int id(char c,int s){
    return ch.find(c)<<n|s;
}

int id(int c,int s){
    return c<<n|s;
}

int dfs(int x){
    if(len[x])return len[x];
    len[x]=1;
    for(int y:g[x]){
        if(dfs(y)>=len[x]){
            len[x]=len[y]+1;
            nxt[x]=y;
        }
    }
    return len[x];
}

void mian(){
    for(int i=0;i<V;i++){
        g[i].clear();
        oc[i].clear();
        len[i]=0;nxt[i]=-1;
    }
    cin>>n;
    for(int i=0;i<n;i++)cin>>S[i];
    for(char c:ch){
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            while(S[i].find(c,v[i].empty()?0:v[i].back()+1)!=S[i].npos)v[i].emplace_back(S[i].find(c,v[i].empty()?0:v[i].back()+1));
        }
        for(int s=0;s<1<<n;s++){
            bool valid=true;
            for(int i=0;i<n;i++)if((s>>i&1)>=v[i].size())valid=false;
            if(valid){
                auto &o=oc[id(c,s)];
                o.resize(n);
                for(int i=0;i<n;i++)o[i]=v[i][s>>i&1];
            }
        }
    }
    for(int i=0;i<V;i++)if(!oc[i].empty()){
        for(int c=0;c<52;c++){
            int s=0;
            for(int j=0;!oc[id(c,s)].empty()&&j<n;j++){
                if(oc[id(c,s)][j]<=oc[i][j])s|=1<<j;
            }
            if(!oc[id(c,s)].empty()){
                bool valid=1;
                for(int j=0;j<n;j++)valid&=oc[id(c,s)][j]>oc[i][j];
                if(valid)g[i].emplace_back(id(c,s));
            }
        }
    }
    int al=0,av=-1;
    for(int i=0;i<V;i++)if(!oc[i].empty()&&dfs(i)>al){
        al=len[i];
        av=i;
    }
    cout<<al<<'\n';
    while(av!=-1){
        cout<<ch[av>>n];
        av=nxt[av];
    }
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(char c='A';c<='Z';c++)ch+=c;
    for(char c='a';c<='z';c++)ch+=c;
    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}