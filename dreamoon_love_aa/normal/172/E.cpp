#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
#define SIZE 1000000
#define MOD 1000000007
using namespace std;
map<string,int>H1;
vector<int>e[SIZE];
string str;
int No,an,len,NN,label[SIZE];
long long now,stack[SIZE],base;
int get(const string& s){
    if(H1.count(s))return H1[s];
    H1[s]=++No;
    return No;
}
void parse(int& x,int father,string& s){
    int y;
    while(x<s.size()){
        for(y=x+1;s[y]!='>';y++);
        if(s[y-1]=='/'){
            NN++;
            label[NN]=get(s.substr(x+1,y-x-2));
            e[father].pb(NN);
            x=y+1;
        }
        else if(s[x+1]!='/'){
            NN++;
            label[NN]=get(s.substr(x+1,y-x-1));
            e[father].pb(NN);
            x=y+1;
            parse(x,NN,s);
        }
        else{
            x=y+1;
            return;
        }
    }
}
void dfs(int x,int v,vector<int>& d){
    int i;
    for(i=0;i<(int)e[x].size();i++){
        if(d[v]==label[e[x][i]]){
            if(v==(int)d.size()-1){
                an++;
                dfs(e[x][i],v,d);
            }
            else dfs(e[x][i],v+1,d);
        }
        else{
            dfs(e[x][i],v,d);
        }
    }
}
void go(vector<int>& d){
    int i;
    an=0;
    dfs(0,0,d);
    printf("%d\n",an);
}
int main(){
    int i,j,k,n,Q;
    cin>>str;
    int tmp=0;
    parse(tmp,0,str);
    scanf("%d",&Q);
    while(Q--){
        vector<int>d;
        char s[20],c;
        bool error=0;
        while(scanf("%s%c",s,&c)){
            if(H1.count(s)){
                d.pb(H1[s]);
            }
            else error=1;
            if(c=='\n')break;
        }
        if(error)puts("0");
        else go(d);
    }
    return 0;
}