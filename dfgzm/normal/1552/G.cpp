#include<bits/stdc++.h>
#define getbit(x) (((chs)&(1ll<<x))?1:0)
#define used(x) (((used)&(1ll<<x))?1:0)
#define ull unsigned long long
using namespace std;
const int maxn=42,maxm=11;
const ull f=(1ll<<60)-1;
int i,j,k,n,m;
vector<int>V[maxm];
ull sum[maxm];
ull s[maxn][maxm];
// int chs[maxn];
ull chs,used;
ull lowbit(ull x){
    return x&(-x);
}
void dfs(int now){
    // cerr<<"dfs "<<now<<' '<<chs<<' '<<used<<endl;
    // cerr<<"Sum="<<sum[now]<<endl;
    if(now>m){
        bool is=true;
        for(int i=0;i<n-1;i++)is&=(used(i)+getbit(i)==1) || (used(i+1)+getbit(i+1)==2);
        if(!is){puts("REJECTED");exit(0);}
        return;
    }else{
        vector<int>tmp;
        int num[3]={0};
        ull lchs=chs,lused=used;
        num[0]=__builtin_popcountll((f-used)&sum[now]);
        num[1]=__builtin_popcountll((used&(f-chs))&sum[now]);
        num[2]=__builtin_popcountll(used&chs&sum[now]);
        ull S2=sum[now],S1=0;
        while(num[1])S1+=lowbit(S2),S2-=lowbit(S2),--num[1];
        for(int i=0;i<=num[0];i++){
            // cerr<<" try "<<i<<' '<<S1<<' '<<S2<<endl;
            int s1=num[1]+i,s2=num[2]+num[0]-i;
            used=lused|sum[now];
            chs=(lchs&(f-sum[now]))|S2;
            dfs(now+1);
            S1+=lowbit(S2);
            S2-=lowbit(S2);
            // S1+=1ll<<(63-__builtin_clzll(S2));
            // S2-=1ll<<(63-__builtin_clzll(S2));
        }chs=lchs;used=lused;
    }
}
int main(){
    cin>>n>>m;
    for(i=1;i<=m;i++){
        int x,y;scanf("%d",&x);
        for(j=1;j<=x;j++){
            scanf("%d",&y);y--;
            sum[i]|=(1ll<<y);
        }
        s[n+1][i]=0;
        for(j=n-1;j>=0;j--)s[j][i]=s[j+1][i]|(sum[i]&(1ll<<j));
    }
    dfs(1);
    puts("ACCEPTED");
}
/*
1011
1111
*/