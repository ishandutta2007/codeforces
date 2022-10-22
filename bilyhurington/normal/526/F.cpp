/*
 * @Author: BilyHurington
 * @Date: 2020-11-05 13:35:24
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-11-05 14:00:38
 */
#include<bits/stdc++.h>
using namespace std;
int n,A[300010];
namespace Segment_Tree{
    pair<int,int> Min[1200010];int tag[1200010];
    pair<int,int> Merge(pair<int,int> p1,pair<int,int> p2){
        if(p1.first==p2.first) return make_pair(p1.first,p1.second+p2.second);
        return p1<p2?p1:p2;
    }
    void Add(int k,int ad){
        Min[k].first+=ad;
        tag[k]+=ad;
    }
    void Push_Down(int k){
        if(!tag[k]) return;
        Add(k<<1,tag[k]);
        Add(k<<1|1,tag[k]);
        tag[k]=0;
    }
    void Build(int k,int l,int r){
        Min[k]=make_pair(0,r-l+1);
        if(l==r) return;
        int mid=(l+r)>>1;
        Build(k<<1,l,mid);
        Build(k<<1|1,mid+1,r);
        Min[k]=Merge(Min[k<<1],Min[k<<1|1]);
    }
    void Modify(int k,int l,int r,int x,int y,int ad){
        if(x<=l&&r<=y){Add(k,ad);return;}
        int mid=(l+r)>>1;Push_Down(k);
        if(x<=mid) Modify(k<<1,l,mid,x,y,ad);
        if(mid<y) Modify(k<<1|1,mid+1,r,x,y,ad);
        Min[k]=Merge(Min[k<<1],Min[k<<1|1]);
    }
    pair<int,int> Query(int k,int l,int r,int x,int y){
        if(x<=l&&r<=y) return Min[k];
        int mid=(l+r)>>1;Push_Down(k);
        if(x<=mid&&mid<y) return Merge(Query(k<<1,l,mid,x,y),Query(k<<1|1,mid+1,r,x,y)); 
        if(x<=mid) return Query(k<<1,l,mid,x,y);
        else return Query(k<<1|1,mid+1,r,x,y);
    }
}
using Segment_Tree::Build;
using Segment_Tree::Modify;
using Segment_Tree::Query;
int sta[300010],vala[300010],tota;//(max)
int stb[300010],valb[300010],totb;//(min)
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d %d",&x,&y);
        A[x]=y;
    }Build(1,1,n);
    long long ans=0;
    for(int i=1;i<=n;i++){
        Modify(1,1,n,1,i,-1);
        while(tota>0&&vala[tota]<=A[i]){
            Modify(1,1,n,sta[tota-1]+1,sta[tota],-vala[tota]);
            tota--;
        }
        sta[++tota]=i;vala[tota]=A[i];
        Modify(1,1,n,sta[tota-1]+1,sta[tota],A[i]);
        while(totb>0&&valb[totb]>=A[i]){
            Modify(1,1,n,stb[totb-1]+1,stb[totb],valb[totb]);
            totb--;
        }
        stb[++totb]=i;valb[totb]=A[i];
        Modify(1,1,n,stb[totb-1]+1,stb[totb],-A[i]);
        ans+=Query(1,1,n,1,i).second;
    }
    printf("%lld",ans);
    return 0;
}