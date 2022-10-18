#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!
 
const int maxn=100005;
 
int n;
int a[maxn];
bool vis[maxn];
 
template<typename T,int S>struct bit{
    T val[S];
    void clear(){memset(val,0,sizeof(val));}
    void chg(int i,T v){for(;i<S;i+=i&-i)val[i]+=v;}
    T qry(int i){T ret=0;for(;i;i-=i&-i){ret+=val[i];}return ret;}
};
bit<int,maxn> b;
bool s[maxn];
pair<int,int>  p[maxn];
int ps[maxn];
pair<int,int> seq[maxn];
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],s[i]=0;
        for(int i=1;i<=n;i++)p[i]={a[i],i};
        sort(p+1,p+1+n);
        for(int i=1;i<=n;i++)ps[p[i].second]=i;
        b.clear();
        for(int i=1;i<=n;i++){
            b.chg(ps[i],1);
            s[i]=(i-b.qry(ps[i]))&1;
        }
        b.clear();
        for(int i=n;i>=1;i--){
            b.chg(ps[i],1);
            s[i]^=b.qry(ps[i]-1)&1;
        }
        for(int i=1;i<=n;i++)seq[i]={ps[i],i};
        sort(seq+1,seq+1+n);
        int cur[2]={0,s[seq[1].second]};
        bool ok=1;
        for(int i=2;i<=n+1;i++){
            if(i==n+1||a[seq[i].second]!=a[seq[i-1].second]){
                if(cur[0]!=cur[1]){
                    ok=0;break;
                }
                cur[i&1]=s[seq[i].second];
                cur[~i&1]=0;
            }else cur[i&1]+=s[seq[i].second];
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}