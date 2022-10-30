#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
typedef long long LL;
map<LL,int> cnt;
int n,idcnt;
map<pair<int,int>,int>id;
map<int,int> cntt[maxn];
int Vx[maxn],Vy[maxn];
int x[maxn];
LL c[maxn];
int a,b;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for (int i=0;i<n;i++){
        scanf("%d%d%d",x+i,Vx+i,Vy+i);
        c[i] = 1LL*Vy[i]-1LL*a*Vx[i];
        cnt[c[i]]++;
    }
    LL ans =0;
    for (int i=0;i<n;i++){
        ans+=cnt[c[i]]-1;
    //    cout<<c[i]<<endl;
    }
    for (int i=0;i<n;i++){
        int t = Vx[i]!=0&&Vy[i]!=0?__gcd(abs(Vx[i]),abs(Vy[i])):Vx[i]==0&&Vy[i]==0?1:Vx[i]==0?abs(Vy[i]):abs(Vx[i]);
        auto temp = make_pair(Vx[i]/t,Vy[i]/t);
        if (!id[temp]){
            id[temp] = ++idcnt;
        }
        cntt[id[temp]][x[i]]++;
    }
    for (int i=1;i<=idcnt;i++){
        int temp =0;
        for (auto tt:cntt[i]){
            int ttt = tt.second;
            temp+=ttt;
            ans+=1LL*ttt*(ttt-1);
        }
       // cout<<temp<<endl;
        ans-=1LL*temp*(temp-1);
    }
    cout<<ans<<endl;
    return 0;
}