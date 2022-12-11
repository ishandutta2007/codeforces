    #include<bits/stdc++.h>
    using namespace std;
    const int N=3e5+50,inf=1e9+10;
    int n,a[N],m,ans[N*4],mi,anss[N];
    int read(){
        int x=0,c;
        while(!isdigit(c=getchar()));
        while(isdigit(c))x=x*10+c-48,c=getchar();
        return x;
    }
    struct node{int l,r,id;bool friend operator <(node a,node b){return a.r<b.r;}}Q[N];
    vector<int>v[N*4];
    vector<int>::iterator it;
    void build(int x,int l,int r){
        for(int i=l;i<=r;i++)v[x].push_back(a[i]);
    	ans[x]=inf;if(l==r)return;
        sort(v[x].begin(),v[x].end());
        int mid=(l+r)>>1;
        build(x<<1,l,mid);build(x<<1|1,mid+1,r);
    }
    void change(int x,int l,int r,int qr,int d){
        if(r<=qr){
            it=lower_bound(v[x].begin(),v[x].end(),d);
            if(it!=v[x].end())ans[x]=min(ans[x],*it-d);
            if(it!=v[x].begin())ans[x]=min(ans[x],d-*(it-1));
            if(ans[x]>=mi)return;//cout<<ans[x]<<endl;
            if(l==r){mi=ans[x];return;}
        }
        int mid=(l+r)>>1;
        if(qr>mid)change(x<<1|1,mid+1,r,qr,d);
        change(x<<1,l,mid,qr,d);
        ans[x]=min(ans[x],min(ans[x<<1],ans[x<<1|1]));
    }
    int query(int x,int l,int r,int ql,int qr){
        if(l>=ql&&r<=qr)return ans[x];
        int mid=(l+r)>>1,ret=inf;
        if(ql<=mid)ret=query(x<<1,l,mid,ql,qr);
        if(qr>mid)ret=min(ret,query(x<<1|1,mid+1,r,ql,qr));
        return ret;
    }
    int main(){
    //    freopen("test.in","r",stdin);
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        build(1,1,n);m=read();//cout<<1<<endl;
        for(int i=1;i<=m;i++)Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
        sort(Q+1,Q+m+1);
        for(int i=1,j=1;i<=m;i++){
            while(j<Q[i].r)j++,mi=inf,change(1,1,n,j-1,a[j]);
            anss[Q[i].id]=query(1,1,n,Q[i].l,j-1);
        }
        for(int i=1;i<=m;i++)printf("%d\n",anss[i]);
        return 0;
    }