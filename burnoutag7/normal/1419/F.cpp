#include<bits/stdc++.h>
using namespace std;

int n,x[1005],y[1005];
int fa[1005];

int find(const int &x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline void unite(int x,int y){
    x=find(x);
    y=find(y);
    fa[y]=x;
}

inline bool seg_pt(const pair<int,int> &seg,const int &pt,const unsigned &t){
    if(find(seg.first)==find(pt)||find(seg.second)==find(pt))return false;
    if(x[seg.first]==x[seg.second]){
        return abs(x[pt]-x[seg.first])<=t&&abs(y[pt]-y[seg.first])<=t&&abs(y[pt]-y[seg.second])<=t;
    }else{
        return abs(y[pt]-y[seg.first])<=t&&abs(x[pt]-x[seg.first])<=t&&abs(x[pt]-x[seg.second])<=t;
    }
    return false;
}

inline bool seg_seg(const pair<int,int> &seg1,const pair<int,int> &seg2,const unsigned &t){
    if(find(seg1.first)==find(seg2.first)
    || find(seg1.first)==find(seg2.second)
    || find(seg1.second)==find(seg2.first)
    || find(seg1.second)==find(seg2.second))return false;
    int ptx=-1,pty=-1;
    if(x[seg1.first]==x[seg1.second]){
        ptx=x[seg1.first];
    }else{
        pty=y[seg1.first];
    }
    if(x[seg2.first]==x[seg2.second]){
        ptx=x[seg2.first];
    }else{
        pty=y[seg2.first];
    }
    if(ptx==-1||pty==-1)return false;
    return abs(ptx-x[seg1.first])<=t
        && abs(ptx-x[seg1.second])<=t
        && abs(ptx-x[seg2.first])<=t
        && abs(ptx-x[seg2.second])<=t
        && abs(pty-y[seg1.first])<=t
        && abs(pty-y[seg1.second])<=t
        && abs(pty-y[seg2.first])<=t
        && abs(pty-y[seg2.second])<=t;
}

inline bool check(const unsigned &t){
    iota(fa+1,fa+1+n,1);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[i]==x[j]&&abs(y[i]-y[j])<=t||y[i]==y[j]&&abs(x[i]-x[j])<=t)unite(i,j);
        }
    }
    int tot=0;
    for(int i=1;i<=n;i++)tot+=fa[i]==i;
    assert(tot);
    if(tot==1)return true;
    if(tot==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(find(i)!=find(j))
                    if(x[i]==x[j]&&abs(y[i]-y[j])<=t<<1
                    || y[i]==y[j]&&abs(x[i]-x[j])<=t<<1
                    || abs(x[i]-x[j])<=t&&abs(y[i]-y[j])<=t)
                        return true;
            }
        }
        return false;
    }
    vector<pair<int,int>> segv; 
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(find(i)!=find(j))
                if(x[i]==x[j]
                || y[i]==y[j]){
                    segv.emplace_back(i,j);
                }
        }
    }
    if(tot==3){
        for(pair<int,int> &seg:segv){
            for(int i=1;i<=n;i++){
                if(seg_pt(seg,i,t))return true;
            }
        }
        return false;
    }
    if(tot==4){
        for(pair<int,int> &seg1:segv){
            for(pair<int,int> &seg2:segv){
                if(seg1!=seg2&&seg_seg(seg1,seg2,t))return true;
            }
        }
        return false;
    }

    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    unsigned l=0,r=2e9,m;
    int ans=-1;
    while(l<=r){
        m=l+r>>1;
        if(check(m)){
            r=m-1;
            ans=m;
        }else{
            l=m+1;
        }
    }
    cout<<ans<<endl;

    return 0;
}