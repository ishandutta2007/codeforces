#include<bits/stdc++.h>
using namespace std;

int n,ans=0x3f3f3f3f;
int a[100005],mxa;
int dis[1000005];
bool u[1000005];
vector<pair<int,int> > g[1000005];

int solve(int rt){
    queue<int> q;
    int res=0x3f3f3f3f;
    q.push(rt);
    memset(dis,-1,sizeof(dis));
    memset(u,0,sizeof(u));
    dis[rt]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(pair<int,int> &e:g[x]){
            int &y=e.first,&z=e.second;
            if(dis[y]==-1){
                dis[y]=dis[x]+1;
                u[z]=1;
                q.push(y);
            }else if(!u[z]){
                u[z]=1;
                res=min(res,dis[x]+dis[y]+1);
            }
        }
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=2;j*j<=a[i];j++){
            while(a[i]%(j*j)==0){
                a[i]/=(j*j);
            }
        }
        if(a[i]==1){
            cout<<1<<endl;
            return 0;
        }
        mxa=max(mxa,a[i]);
        bool fl=true;
        for(int j=2;j*j<=a[i];j++){
            if(a[i]%j==0){
                g[j].push_back(make_pair(a[i]/j,i));
                g[a[i]/j].push_back(make_pair(j,i));
                fl=false;
                break;
            }
        }
        if(fl){
            g[1].push_back(make_pair(a[i],i));
            g[a[i]].push_back(make_pair(1,i));
        }
    }
    mxa=sqrt(mxa);
    for(int i=1;i<=mxa;i++){
        if(!g[i].empty())ans=min(ans,solve(i));
    }
    cout<<(ans==0x3f3f3f3f?-1:ans)<<endl;

    return 0;
}