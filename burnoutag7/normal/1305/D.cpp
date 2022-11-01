#include<bits/stdc++.h>
using namespace std;

int n,rt,tot;
vector<int> g[1005];
int d[1005];
bool b[1005];

void dfs(int x,int p){
    for(int i=0;i<g[x].size();i++){
        int &y=g[x][i];
        if(!b[y]&&y!=p){
            d[y]=d[x]+1;
            dfs(y,x);
        }
    }
}

void ban(int x,int p){
    tot--;
    b[x]=1;
    for(int i=0;i<g[x].size();i++){
        int &y=g[x][i];
        if(!b[y]&&y!=p){
            ban(y,x);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;tot=n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rt=1;
    for(int tms=0;tms<n>>1&&tot>1;tms++){
        memset(d,-1,sizeof(d));
        d[rt]=0;
        dfs(rt,-1);
        int lp=rt;
        for(int i=1;i<=n;i++){
            if(!b[i]&&d[i]>d[lp])lp=i;
        }
        memset(d,-1,sizeof(d));
        d[lp]=0;
        dfs(lp,-1);
        int rp=lp;
        for(int i=1;i<=n;i++){
            if(!b[i]&&d[i]>d[rp])rp=i;
        }
        cout<<"? "<<lp<<' '<<rp<<endl;
        int mid;
        cin>>mid;
        assert(mid!=-1);
        memset(d,-1,sizeof(d));
        d[mid]=0;
        dfs(mid,-1);
        while(d[lp]>1){
            for(int i=0;i<g[lp].size();i++)
                if(!b[g[lp][i]]&&d[g[lp][i]]<d[lp]){lp=g[lp][i];break;}
        }
        while(d[rp]>1){
            for(int i=0;i<g[rp].size();i++)
                if(!b[g[rp][i]]&&d[g[rp][i]]<d[rp]){rp=g[rp][i];break;}
        }
        if(lp!=mid)ban(lp,mid);
        if(rp!=mid)ban(rp,mid);//cerr<<lp<<' '<<mid<<' '<<rp<<endl;
        rt=mid;
    }
    cout<<"! "<<rt<<endl;

    return 0;
}