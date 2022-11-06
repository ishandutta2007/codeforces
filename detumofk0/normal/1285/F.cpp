#include <bits/stdc++.h>
#define N 100005
using namespace std;
struct pt { int k,sl; };
vector <pt> uoc[N];
vector <int> vec[N],nto;
long long a[N],ma,x,kq;
int n,i,j,ts[N],p[N],l[N],r[N],mid[N],f[N],cnt[N],t[N];
void vet(int i,int sl,int k)
{
    if(i==nto.size()) { uoc[x].push_back({ k,sl }); return ; }
    vet(i+1,sl,k); vet(i+1,sl+1,k*nto[i]);
}
void pt(int n)
{
    nto.clear();
    while(n>1)
    {
        int x=p[n]; nto.push_back(x);
        while(n%x==0) n/=x;
    }
    vet(0,0,1);
}
int main()
{
    //freopen("ntu.inp","r",stdin);
    //freopen("ntu.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++) { cin>>x; ts[x]=1; ma=max(ma,x); kq = max(kq, x);}
    for(i=1;i<=ma;i++) p[i]=i;
    for(i=2;i*i<=ma;i++)
        if(p[i]==i)
            for(j=2*i;j<=ma;j+=i) p[j]=i;
    for(x=1;x<=ma;x++) pt(x);
    for(x=1;x<=ma;x++)
    {
        n=0;
        for(i=x;i<=ma;i+=x)
            for(j=1;j<=ts[i];j++) a[++n]=i/x;
        for(i=2;i<=n;i++) { l[i]=1; r[i]=i-1; }
        for(int k=1;k<=17;k++)
        {
            for(i=2;i<=n;i++)
            {
                
                mid[i]=(l[i]+r[i]+1)>>1; f[i]=0;
                if(l[i]<r[i]) vec[mid[i]].push_back(i);
            }
            for(i=1;i<=n;i++)
            {
                while(vec[i].size()>0)
                {
                    int vt=vec[i].back(); vec[i].pop_back();
                    for(j=0;j<uoc[a[vt]].size();j++)
                        if(uoc[a[vt]][j].sl%2==0) f[vt]+=cnt[uoc[a[vt]][j].k]; else f[vt]-=cnt[uoc[a[vt]][j].k];
                }
                if(i>1 && l[i]<r[i])
                {
                    if(k==1)
                    {
                        t[i]=0;
                        for(j=0;j<uoc[a[i]].size();j++)
                            if(uoc[a[i]][j].sl%2==0) t[i]+=cnt[uoc[a[i]][j].k]; else t[i]-=cnt[uoc[a[i]][j].k];
                    }
                   // if(x==1 && i==3) cerr<<l[i]<<" "<<r[i]<<" "<<mid[i]<<" "<<t-f[i]<<'\n';
                    if(t[i]-f[i]>0) l[i]=mid[i]; else r[i]=mid[i];
                }
                for(j=0;j<uoc[a[i]].size();j++) cnt[uoc[a[i]][j].k]++;
            }
            for(i=1;i<=n;i++)
                for(j=0;j<uoc[a[i]].size();j++) cnt[uoc[a[i]][j].k]--;
        }
        for(i=2;i<=n;i++)
            if(__gcd(a[i],a[l[i]])==1) kq=max(kq,a[i]*a[l[i]]*x);
    }
    cout<<kq;
}