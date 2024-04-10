#include<bits/stdc++.h>
using namespace std;
#define rep(a) for(int i=0; i<a; i++)
int n,a[1<<20],x,cnt[3],MOD=1000000007;
long long ans;
bool vis[1<<20],flag;

signed main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(n) scanf("%d",&a[i]);
        rep(n) a[i]--,vis[i]=0;
        vector<int> vec;
        rep(n) if(!vis[i]){
            x=vis[i]=1;
            for(int j=a[i]; j!=i; j=a[j]) x++,vis[j]=1;
            vec.push_back(x);
        }
        rep(3) cnt[i]=0;
        for(auto i: vec) cnt[i%3]++;
        ans=1;
        rep(n/3-1) ans=ans*3%MOD;
        int c1=cnt[1]-(n%3==1),c2=cnt[2]-(n%3==2),ans2;
        x=min(c1,c2)+2*abs(c1-c2)/3;
        x=2*x+n/3-vec.size();
        if(n%3==0) printf("%d %d\n",ans*3%MOD,x);
        else if(n%3==1){
            flag=0;
            for(auto i: vec) if(i%3==1&&i>1) flag=1;
            if(cnt[2]>cnt[1]) ans2=x-1;
            else if(cnt[1]>1||cnt[2]>0||flag) ans2=x+1;
            else ans2=x+3;
            printf("%d %d\n",ans*4%MOD,min(x+2*!flag,ans2));
        }
        else printf("%d %d\n",ans*6%MOD,x+1);
    }
    return 0;
}