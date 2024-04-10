#include<bits/stdc++.h>
using namespace std;

struct AC{
    int sz,tot;
    vector<vector<int>> g;
    vector<int> pat,fail;
    AC(){
        sz=1e5+5;
        tot=0;
        g.resize(sz,vector<int>(10,0));
        pat.resize(sz,0);
        fail.resize(sz,0);
    }
    int add(string s){
        int x=0;
        for(char &c:s){
            if(!g[x][c-'0']){
                g[x][c-'0']=++tot;
            }
            x=g[x][c-'0'];
        }
        pat[x]=1;
        return x;
    }
    void build(){
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int c=0;c<10;c++){
                if(g[x][c]){
                    if(x)fail[g[x][c]]=g[fail[x]][c];
                    q.push(g[x][c]);
                }else{
                    g[x][c]=g[fail[x]][c];
                }
            }
        }
    }
};

inline bool check(const string &s,const int &x){
    for(int i=0;i<s.size();i++){
        int sum=0;
        for(int j=i;j<s.size();j++){
            sum+=s[j]-'0';
            if(sum!=x&&x%sum==0)return false;
        }
    }
    return true;
}

void generate(const string &s,const int &sum,const int &x,vector<string> &p){
    if(sum==x&&check(s,x))p.emplace_back(s);
    if(sum>=x)return;
    for(char d='1';d<='9';d++)generate(s+d,sum+d-'0',x,p);
}

int x;
string s;
vector<string> prime;
AC atm;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>x;
    generate("",0,x,prime);
    for(string &t:prime)atm.add(t);
    atm.build();
    vector<int> cur(atm.tot,1e9);
    cur[0]=0;
    for(char &c:s){
        vector<int> nxt(atm.tot,1e9);
        for(int i=0;i<atm.tot;i++)if(cur[i]!=1e9){
            nxt[i]=min(nxt[i],cur[i]+1);
            int j=atm.g[i][c-'0'];
            if(!atm.pat[j])nxt[j]=min(nxt[j],cur[i]);
        }
        swap(nxt,cur);
    }
    cout<<*min_element(cur.begin(),cur.end())<<endl;

    return 0;
}