/*
 * @Author: BilyHurington
 * @Date: 2020-09-30 13:26:08
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-30 13:48:14
 */
#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[150010];
struct node{
    vector<pair<int,int> > Num;
    node operator + (const node &P) const {
        node ans=P;
        for(int i=0;i<Num.size();i++){
            bool pd=0;
            for(int j=0;j<ans.Num.size();j++){
                if(Num[i].first==ans.Num[j].first){
                    ans.Num[j].second+=Num[i].second;
                    pd=1;break;
                }
            }
            if(pd) continue;
            if(ans.Num.size()<p){
                ans.Num.push_back(Num[i]);
                continue;
            }
            int minx=0;
            for(int j=0;j<ans.Num.size();j++){
                if(ans.Num[j].second<ans.Num[minx].second){
                    minx=j;
                }
            }
            if(ans.Num[minx].second<Num[i].second){
                int x=ans.Num[minx].second;
                ans.Num[minx]=Num[i];
                for(int j=0;j<ans.Num.size();j++){
                    ans.Num[j].second-=x;
                }
            }
            else{
                for(int j=0;j<ans.Num.size();j++){
                    ans.Num[j].second-=Num[i].second;
                }
            }
        }
        return ans;
    }
}nd[600010];
int tag[600010];
void add(int k,int l,int r,int x){
    tag[k]=x;
    nd[k].Num.resize(1);
    nd[k].Num[0]=make_pair(x,r-l+1);
}
void push_down(int k,int l,int r){
    if(!tag[k]) return;
    int mid=(l+r)>>1;
    add(k<<1,l,mid,tag[k]);
    add(k<<1|1,mid+1,r,tag[k]);
    tag[k]=0;
}
void build(int k,int l,int r){
    if(l==r){
        add(k,l,r,a[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    nd[k]=nd[k<<1]+nd[k<<1|1];
}
void modify(int k,int l,int r,int x,int y,int ad){
    if(x<=l&&r<=y){add(k,l,r,ad);return;}
    int mid=(l+r)>>1;
    push_down(k,l,r);
    if(x<=mid) modify(k<<1,l,mid,x,y,ad);
    if(mid<y) modify(k<<1|1,mid+1,r,x,y,ad);
    nd[k]=nd[k<<1]+nd[k<<1|1];
}
node query(int k,int l,int r,int x,int y){
    if(x<=l&&r<=y) return nd[k];
    int mid=(l+r)>>1;
    push_down(k,l,r);
    if(x<=mid&&mid<y) return query(k<<1,l,mid,x,y)+query(k<<1|1,mid+1,r,x,y);
    if(x<=mid) return query(k<<1,l,mid,x,y);
    else return query(k<<1|1,mid+1,r,x,y);
}
int main(){
    scanf("%d %d %d",&n,&m,&p);p=100/p;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=1,opt,x,y,z;i<=m;i++){
        scanf("%d %d %d",&opt,&x,&y);
        if(opt==1){
            scanf("%d",&z);
            modify(1,1,n,x,y,z);
        }
        else{
            node ans=query(1,1,n,x,y);
            printf("%d ",ans.Num.size());
            for(int i=0;i<ans.Num.size();i++){
                printf("%d ",ans.Num[i].first);
            }
            printf("\n");
        }
    }
    return 0;
}