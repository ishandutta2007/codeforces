#include<bits/stdc++.h>
using namespace std;

void suffixarray(int n,char *s,int *sa,int *rk){
    static int ork[2000005],id[1000005],cnt[1000005];
    auto equal=[&](int x,int y,int w)->bool{
        return ork[x]==ork[y]&&ork[x+w]==ork[y+w];
    };
    memset(ork+1,0,n*2*sizeof(int));
    memset(cnt,0,305*sizeof(int));
    for(int i=1;i<=n;i++)cnt[rk[i]=s[i]]++;
    for(int i=1;i<=300;i++)cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;i--){
        sa[cnt[rk[i]]--]=i;
    }
    for(int w=1,m=300,p;w<n;w<<=1,m=p){
        p=0;
        for(int i=n;i>n-w;i--)id[++p]=i;
        for(int i=1;i<=n;i++)if(sa[i]>w)id[++p]=sa[i]-w;
        memset(cnt,0,(m+1)*sizeof(int));
        for(int i=1;i<=n;i++)cnt[rk[i]]++;
        for(int i=1;i<=m;i++)cnt[i]+=cnt[i-1];
        for(int i=n;i>=1;i--)sa[cnt[rk[id[i]]]--]=id[i];
        p=0;
        memcpy(ork+1,rk+1,n*sizeof(int));
        for(int i=1;i<=n;i++)rk[sa[i]]=p+=!equal(sa[i],sa[i-1],w);
        if(p==n)return;
    }
}

void height(int n,char *s,int *sa,int *rk,int *h){
    for(int i=1,k=0;i<=n;i++){
        k-=(bool)k;
        while(s[i+k]==s[sa[rk[i]-1]+k])k++;
        h[rk[i]]=k;
    }
}

struct SparseTable{
    vector<vector<int>> st;
    int n,m;
    SparseTable(){n=m=0;}
    SparseTable(int *a,int sz){
        n=sz;m=0;
        while(1<<m<n)m++;
        st.resize(m+1,vector<int>(n+1));
        for(int i=1;i<=n;i++)st[0][i]=a[i];
        for(int j=1;j<=m;j++)for(int i=1;i+(1<<j)-1<=n;i++)st[j][i]=min(st[j-1][i],st[j-1][i+(1<<j-1)]);
    }
    int qry(int l,int r){
        int s=31-__builtin_clz(r-l+1);
        return min(st[s][l],st[s][r-(1<<s)+1]);
    }
};

int n,sa[1000005],rk[1000005],h[1000005],ans[1000005];
char s[1000005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s+1;
    suffixarray(n,s,sa,rk);
    height(n,s,sa,rk,h);
    SparseTable st(h,n);
    auto lcp=[&](int a,int b)->int{
        a=rk[a];
        b=rk[b];
        if(a>b)swap(a,b);
        return st.qry(a+1,b);
    };
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n/2;i++){
        int l=0,r=i-1,m,res=-1;
        while(l<=r){
            m=l+r>>1;
            if(lcp(i-m,n+1-i-m)>=2*m+1){
                res=m;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        if(res!=-1){
            ans[i-res]=max(ans[i-res],2*res+1);
        }
    }
    for(int i=1;i<=n+1>>1;i++){
        cout<<ans[i]<<' ';
        ans[i+1]=max(ans[i+1],ans[i]-2);
    }

    return 0;
}