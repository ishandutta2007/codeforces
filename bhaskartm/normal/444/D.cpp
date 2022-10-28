#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,x,y) for(i=x;i<=y;i++)
#define pb push_back
#define mp make_pair
#define upmin(x,y) x=min(x,y)
const int L=50010,R=4,N=L*R,Q=100010,inf=int(1e9);
int l,q,g,all,i,j,k,p,x,y,p1,p2,res,tot;char s[L],s0[11];
int h[600000],ans[Q],d[R+1][L],tmp[N],li[N],l2[N],pos[N],num[N],vg[N],la[L],ne[L];vector<int> v[N];
struct ask{int x,y,lx,ly,nn;}c[Q];
bool cmp(ask a,ask b){return mp(a.x,a.y)<mp(b.x,b.y);}
int ins(int x){if(h[x])return h[x];num[++tot]=x;return h[x]=tot;}
int getstr(int&l0){
    scanf("%s",s0+1);int i,res;l0=strlen(s0+1);
    for(res=0,i=1;i<=l0;i++)res=res*27+(s0[i]-'a'+1);return res;
}
void calcd(int id,int l0){
    int i,j,k,la0,ne0,now;
    rep(j,1,R){
        for(int k=0;k<=l;k++)la[k]=-inf,ne[k]=inf;
        for(int k=0;k<vg[id];k++){
            now=v[id][k];
            la0=(k==0)?1:v[id][k-1]+1;
            ne0=(k==vg[id]-1)?l:v[id][k+1]-1;
            rep(i,now,ne0)la[i]=now;
            rep(i,la0,now)ne[i]=now;
        }
        rep(i,1,l)d[j][i]=min(max(i+j,ne[i]+l0)-i,max(i+j,la[i]+l0)-la[i]);
    }
}
int main(){
    scanf("%s%d",s+1,&q);l=strlen(s+1);
	rep(i,1,l)for(res=0,j=1;j<=R&&i+j-1<=l;j++)
    l2[++all]=j,v[pos[all]=ins(res=res*27+(s[i+j-1]-'a'+1))].pb(li[all]=i);
    rep(i,1,tot)vg[i]=v[i].size();
    rep(i,1,q){
        int ida=h[getstr(p1)],idb=h[getstr(p2)];
        if(ida==0||idb==0)ans[i]=-1;
        else{ans[i]=inf;if(vg[ida]<vg[idb])swap(ida,ida);c[++g]=(ask){ida,idb,p1,p2,i};}
    }
    sort(c+1,c+1+g,cmp);
    for(i=1;i<=g;i=j+1){
        long long totcnt=0;
        for(j=i;j<=g&&c[j].x==c[i].x;j++)totcnt+=vg[c[j].y]+vg[c[i].x];j--;
        if(totcnt>all){
            calcd(c[i].x,c[i].lx);    
            rep(k,1,tot)tmp[k]=inf;
            rep(k,1,all)upmin(tmp[pos[k]],d[l2[k]][li[k]]);
            rep(k,i,j)upmin(ans[c[k].nn],tmp[c[k].y]);
        }
        else
        rep(k,i,j)
        for(p1=p2=0,x=c[k].x,y=c[k].y;p1<vg[x]&&p2<vg[y];v[x][p1]<=v[y][p2]?p1++:p2++)
        upmin(ans[c[k].nn],max(v[x][p1]+c[k].lx,v[y][p2]+c[k].ly)-min(v[x][p1],v[y][p2]));
    }
    rep(i,1,q)printf("%d\n",ans[i]);
    return 0;
}