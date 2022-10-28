#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 100000000
#define fi first
#define se second
#define N 100005
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int c[2][N*4],s[2][N],a[N],qw;
void build_tree(int o,int L,int R)
{
    if(L==R)
    {
        for(int i=0;i<=1;i++)
            c[i][o]=s[i][L];
        return;
    }
    int mid=(L+R)>>1;
    build_tree(o<<1,L,mid);
    build_tree(o<<1|1,mid+1,R);
    for(int i=0;i<=1;i++)
        c[i][o]=max(c[i][o<<1],c[i][o<<1|1]);
}

int Query(int o,int L,int R,int i)
{
    if(c[i][o]<qw) return INF;
    if(L==R)
        return L;
    int mid=(L+R)>>1;
    if(c[i][o<<1]>=qw)
        return Query(o<<1,L,mid,i);
    else return Query(o<<1|1,mid+1,R,i);
}

pii rel[N];
int w[2],sum[2];
int main()
{
    int n,i,wn,ans=0,l[2],j,flag,cou;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]),a[i]--;
        s[0][i]=s[0][i-1],s[1][i]=s[1][i-1];
        s[a[i]][i]++;
    }
    build_tree(1,1,n);
    wn=a[n];
    for(i=1;i<=n;i++)
    {
        flag=1,cou=0;
        for(j=0;j<=1;j++)
            w[j]=0,sum[j]=0,l[j]=0;
        j=0;
        while(l[j]+1<=n)
        {
            cou++;
            for(j=0;j<=1;j++)
            {
                qw=sum[j]+i;
                //cout<<qw<<endl;
                l[j]=Query(1,1,n,j);
            }
            //cout<<l[0]<<' '<<l[1]<<endl;
            if(l[0]<l[1])
                j=0;
            else
                j=1;
            //printf("j=%d %d\n",j,l[j]);
            if(l[j]==INF)
            {
                flag=0;
                //printf("l[j]=%d\n",l[j]);
                break;
            }
            sum[j]+=i;
            sum[j^1]=s[j^1][l[j]];
            w[j]++;
        }
        //printf("%d %d %d\n",w[wn],w[wn^1],cou);
        if(flag&&w[wn]>w[wn^1])
            rel[++ans]=make_pair(w[wn],i);
    }
    cout<<ans<<endl;
    sort(rel+1,rel+1+ans);
    for(i=1;i<=ans;i++)
        printf("%d %d\n",rel[i].fi,rel[i].se);
    cout<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);