#include<bits/stdc++.h>
using namespace std;

int n,m,d;
vector<int> g[100005];
int md[100005];
bool u[100005];
int cnt;
int dd[100005];//dist down
int du[100005];//dist up

void ddd(int x){//do dist down (or King Dedede?) (but why i write this)
    u[x]=true;
    dd[x]=(md[x]?0:-1);
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(!u[y]){
            ddd(y);
            if(dd[y]!=-1){
                dd[x]=max(dd[x],dd[y]+1);
            }
        }
    }
}

void ddu(int x,int p){//do dist up (no more King Dedede now) (kicked out by String Kerby (maybe))
    int mx=-1,smx=-1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==p)continue;
        if(dd[y]>mx){
            smx=mx;
            mx=dd[y];
        }else{
            if(dd[y]>smx){
                smx=dd[y];
            }
        }
    }
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==p)continue;
        int sd=(dd[y]==mx)?smx:mx;
        if(sd!=-1)sd+=2;
        du[y]=sd;
        if(du[x]!=-1)du[y]=max(du[y],du[x]+1);
        if(md[y])du[y]=max(du[y],0);
        ddu(y,x);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>d;
    for(int i=1;i<=m;i++){
        int t;
        cin>>t;
        md[t]=true;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ddd(1);
    du[1]=(int(md[1]))-1;
    ddu(1,-1);
    for(int i=1;i<=n;i++){
        cnt+=(dd[i]<=d)&&(du[i]<=d);
    }
    cout<<cnt<<endl;

    return 0;
}