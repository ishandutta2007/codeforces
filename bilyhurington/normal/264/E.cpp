#include<bits/stdc++.h>
using namespace std;
int n,m,id[200100],a[200100];
struct segment_tree{
    int maxn[800100],dp[200100];
    void modify(int k,int l,int r,int x,int val){
        if(l==r){
            maxn[k]=val;
            return;
        }
        int mid=(l+r)/2;
        if(x<=mid) modify(2*k,l,mid,x,val);
        else modify(2*k+1,mid+1,r,x,val);
        maxn[k]=max(maxn[2*k],maxn[2*k+1]);
    }
    int query(int k,int l,int r,int x,int y){
        if(x<=l&&r<=y) return maxn[k];
        int mid=(l+r)/2,ans=0;
        if(x<=mid) ans=max(ans,query(2*k,l,mid,x,y));
        if(mid<y) ans=max(ans,query(2*k+1,mid+1,r,x,y));
        return ans;
    }
    void insert(int p){
        dp[p]=query(1,0,m+10,0,p-1)+1;
        modify(1,0,m+10,p,dp[p]);
    }
}loc,wt;
priority_queue<int> q;
stack<int> s;
int main(){
    int opt,x,val;
    scanf("%d %d",&n,&m);
    for(int ti=1;ti<=m;ti++){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d %d",&x,&val);
            x=n+1-x;
            val=ti+10-val;
            a[x]=val;
            id[val]=x;
            q.push(x);
            for(int i=val+1;i<val+10;i++){
                if(id[i]) loc.modify(1,0,m+10,id[i],0);
            }
            for(int i=val;i<val+10;i++){
                if(id[i]){
                    loc.insert(id[i]);
                    wt.dp[i]=loc.dp[id[i]];
                    wt.modify(1,0,m+10,i,wt.dp[i]);
                }
            }
        }
        else{
            scanf("%d",&x);
            for(int i=1;i<=x;i++){
                s.push(q.top());
                wt.modify(1,0,m+10,a[s.top()],0);
                q.pop();
            }
            loc.modify(1,0,m+10,s.top(),0);
            id[a[s.top()]]=0;
            a[s.top()]=0;
            s.pop();
            while(s.size()){
                q.push(s.top());
                wt.insert(a[s.top()]);
                loc.dp[s.top()]=wt.dp[a[s.top()]];
                loc.modify(1,0,m+10,s.top(),loc.dp[s.top()]);
                s.pop();
            }
        }
        printf("%d\n",loc.maxn[1]);
    }
}