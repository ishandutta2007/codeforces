#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;
const int maxl=20;
const int maxt=maxn*2;
char ch[maxn];
int s[maxn],rgt[maxn];
int sa[maxn],rnk[maxn],pre[maxn<<1],cnt[maxn],h[maxn];
int id[maxn];
vector<int> vec[maxn];
long long ans[maxn];

int w,k,n=0,t;
int p[maxt],len[maxt],li[maxt],ri[maxt],fa[maxt][maxl];
long long sum[maxt];
int prv[maxn],dif[maxt];

int grt(int u){return p[u]==u?u:p[u]=grt(p[u]);}

int main(){
    cin>>w>>k;
    for(int i=1;i<=w;i++){
        cin>>ch;
        int l=strlen(ch);
        int rp=n+l;
        for(int j=0;j<l;j++){
            id[++n]=i;
            s[n]=ch[j];
            rgt[n]=rp;
        }
        s[++n]=i+256;
    } 
    for(int i=1;i<=n;i++)cnt[s[i]]++;
    for(int i=1;i<=256+w;i++)cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;i--)sa[cnt[s[i]]--]=i;
    rnk[sa[1]]=1;for(int i=2;i<=n;i++)rnk[sa[i]]=rnk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
    int m=rnk[sa[n]];
    for(int k=1;k<=n&&m<n;k<<=1){
        int t=0;
        for(int i=n-k+1;i<=n;i++)pre[++t]=i;
        for(int i=1;i<=n;i++)if(sa[i]>k)pre[++t]=sa[i]-k;
        for(int i=1;i<=m;i++)cnt[i]=0;
        for(int i=1;i<=n;i++)cnt[rnk[i]]++;
        for(int i=1;i<=m;i++)cnt[i]+=cnt[i-1];
        for(int i=n;i>=1;i--)sa[cnt[rnk[pre[i]]]--]=pre[i];
        for(int i=1;i<=n;i++)pre[i]=rnk[i];
        rnk[sa[1]]=1;
        for(int i=2;i<=n;i++)rnk[sa[i]]=rnk[sa[i-1]]+(pre[sa[i]]!=pre[sa[i-1]]||pre[sa[i]+k]!=pre[sa[i-1]+k]);
        m=rnk[sa[n]];
    }
    for(int i=1;i<=n;i++){
        if(rnk[i]==1)h[1]=0;
        else{
            int ch=h[rnk[i-1]];ch-=!!ch;
            while(s[i+ch]==s[sa[rnk[i]-1]+ch])ch++;
            h[rnk[i]]=ch;
        }
    }
    for(int i=2;i<=n;i++)vec[h[i]].push_back(i);
    for(int i=1;i<=n;i++)p[i]=i,len[i]=(id[sa[i]]?rgt[sa[i]]-sa[i]+1:0),li[i]=ri[i]=i;
    t=n;
    for(int i=n;i>=1;i--){
        for(int j=0;j<vec[i].size();j++){
            int rv=vec[i][j],lv=rv-1;lv=grt(lv);rv=grt(rv);
            ++t;p[t]=t;
            p[lv]=t;p[rv]=t;len[t]=i;li[t]=li[lv];ri[t]=ri[rv];
            fa[lv][0]=fa[rv][0]=t;
        }
    }
    for(int i=1;i<maxl;i++)for(int j=1;j<=t;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
    for(int i=1;i<=n;i++)if(id[sa[i]]){
        int lv=prv[id[sa[i]]];
        int cu=i;
        dif[i]++;
        for(int j=maxl-1;j>=0;j--)if(fa[cu][j]&&li[fa[cu][j]]>lv)cu=fa[cu][j];
        dif[fa[cu][0]]--;
        prv[id[sa[i]]]=i;
    }
    for(int i=1;i<=t;i++)dif[fa[i][0]]+=dif[i];
    for(int i=1;i<=t;i++)if(dif[i]>=k)sum[i]=len[i]-len[fa[i][0]];
    for(int i=t;i>=1;i--)if(fa[i][0])sum[i]+=sum[fa[i][0]];
    for(int i=1;i<=n;i++)if(id[sa[i]])ans[id[sa[i]]]+=sum[i];
    for(int i=1;i<=w;i++)cout<<ans[i]<<' ';
    return 0;
}