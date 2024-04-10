#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
int n;
int x[maxn],y[maxn];
int yl;
int mp[maxn];
bool vis[maxn];

signed  main(){
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while (q--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>x[i];
        sort(x+1,x+1+n);
        int ans=0;
        yl=1;
        y[1]=x[1];
        for(int i=2;i<=n;i++){
            if(x[i]!=x[i-1]){
                y[++yl]=x[i];
            }
        }
        for(int i=1;i<=yl;i++){
            mp[y[i]]=i;
            vis[i]=1;
        }
        ans=y[yl];
        for(int i=1;i<=yl;i++){
            if(y[yl]%y[i]==0){
                vis[i]=0;
            }
        }
        int fd=-1;
        for(int i=yl-1;i>=1;i--){
            if(vis[i]){
                fd=i;
                break;
            }
        }
        if(fd!=-1){
            ans+=y[fd];
            for(int i=1;i<fd;i++){
                if(y[fd]%y[i]==0) vis[i]=0;
            }
            int g2=-1;
            for(int i=fd-1;i>=1;i--){
                if(vis[i]){
                    g2=i;
                    break;
                }
            }
            if(g2!=-1) ans+=y[g2];
        }
        int h1=mp[y[yl]/2],h2=mp[y[yl]/3],h3=mp[y[yl]/5];
        if(y[h1]*2==y[yl]&&y[h2]*3==y[yl]&&y[h3]*5==y[yl]){
            ans=max(ans,y[h1]+y[h2]+y[h3]);
        }
        cout<<ans<<'\n';
    }
    

    return 0;
}