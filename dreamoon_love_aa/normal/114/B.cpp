#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
string name[16];
map<string,int>hash;
set<string>an,tmp;
int ban[16][16];
void dfs(int x,int n){
    if(x==n){
        if(tmp.size()>an.size())an=tmp;
        return;
    }
    set<string>::iterator it;
    for(it=tmp.begin();it!=tmp.end();it++){
        if(ban[hash[*it]][x])break;
    }
    if(it==tmp.end()){
        tmp.insert(name[x]);
        dfs(x+1,n);
        tmp.erase(name[x]);
    }
    dfs(x+1,n);
}
main(){
    int n,m,i;
    string s1,s2;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>name[i];
        hash[name[i]]=i;
    }
    for(i=0;i<m;i++){
        cin>>s1>>s2;
        ban[hash[s1]][hash[s2]]=1;
        ban[hash[s2]][hash[s1]]=1;
    }
    dfs(0,n);
    cout<<an.size()<<endl;
    set<string>::iterator it;
    for(it=an.begin();it!=an.end();it++){
        cout<<*it<<endl;
    }
}