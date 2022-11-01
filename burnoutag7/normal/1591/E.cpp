#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

const int SIZ=(1<<25);
char buf1[SIZ],*p1=buf1,*p2=buf1;
char buf2[SIZ],*p3=buf2,*p4=buf2;
char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
void pchar(char c){*p4++=c;if(p4-p3==SIZ)fwrite(buf2,1,SIZ,stdout),p4=buf2;}
void output(){fwrite(buf2,1,p4-p3,stdout);}
void read(int &ret){ret=0;int c;while((c=gchar())>'9'||c<'0');ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';}
void write(int x){if(x<0)pchar('-'),x=-x;if(x>9)write(x/10);pchar(x%10+'0');}

struct query{
    int l,k,id;
    query(int _l,int _k,int _id):l(_l),k(_k),id(_id){}
};

int n,q,col[1000005],ans[1000005],occ[1000005];
vector<query> qs[1000005];
vector<int> g[1000005];
tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> t;

void dfs(int x){
    t.erase({occ[col[x]],col[x]});
    t.insert({++occ[col[x]],col[x]});
    for(auto &[l,k,id]:qs[x]){
        int p=t.order_of_key({l,0})+k-1;
        ans[id]=p>=t.size()?-1:t.find_by_order(p)->second;
    }
    for(int y:g[x])dfs(y);
    t.erase({occ[col[x]],col[x]});
    t.insert({--occ[col[x]],col[x]});
}

void mian(){
    for(int i=1;i<=n;i++)qs[i].clear(),g[i].clear();
    read(n);
    read(q);
    for(int i=1;i<=n;i++)read(col[i]);
    for(int i=2,f;i<=n;i++){
        read(f);
        g[f].emplace_back(i);
    }
    for(int i=1;i<=q;i++){
        int v,l,k;
        read(v);
        read(l);
        read(k);
        qs[v].emplace_back(l,k,i);
    }
    dfs(1);
    for(int i=1;i<=q;i++)write(ans[i]),pchar(i==q?'\n':' ');
}

int main(){

    for(int i=1;i<=1e6;i++)t.insert({0,i});

    int T;
    read(T);
    while(T--)mian();
    output();

    return 0;
}