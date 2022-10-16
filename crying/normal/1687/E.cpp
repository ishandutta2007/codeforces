#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1e5+10,LIM=1e6,INF=1e9;
int prime[LIM+10],tag[LIM+10],prime_tot,tt[LIM+10];
int n,a[MAXN],minp[LIM+10];

void prime_init(){
    rep(i,2,LIM){
        if(!tag[i]){
            prime[++prime_tot]=i;
            minp[i]=i;
        }
        rep(j,1,prime_tot)if(prime[j]*i>LIM)break;else{
            tag[prime[j]*i]=1;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
}
set<int>S;
vector<int>D;
int cnt[MAXN],len;
int pcnt[1<<14];
int P(int x){return odd(x)?(-1):(1);}
void solve(){
    for(auto u:S)D.push_back(u);
    len=D.size();
    int all=0;

    rep(i,1,(1<<len)-1)all+=abs(P(pcnt[i])*(pcnt[i]-2));
    cout<<all<<"\n";
    
    rep(i,1,(1<<len)-1){
        int cnt=P(pcnt[i])*(pcnt[i]-2);
        if(cnt==0)continue;
        if(cnt>0){
            while(cnt--){
                cout<<"0 "<<pcnt[i]<<" ";
                rep(j,0,len-1)if(i>>j&1)cout<<D[j]<<" ";
                cout<<"\n";     
            }
        }else{
            cnt=-cnt;
            while(cnt--){
                cout<<"1 "<<pcnt[i]<<" ";
                rep(j,0,len-1)if(i>>j&1)cout<<D[j]<<" ";
                cout<<"\n";
            }
        }
    }
}
int check(){
    rep(i,1,n){
        int num=a[i];
        while(num!=1){
            int p=minp[num];
            tt[p]++;
            while(num%p==0)num/=p;
        }
    }
    rep(i,1,prime_tot)if(a[1]%prime[i]==0){
        int flag=1;
        rep(j,2,n)flag&=(a[j]%prime[i]==0);
        if(flag)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);

    rep(i,1,(1<<14)-1)pcnt[i]=pcnt[i^lowbit(i)]+1;
    prime_init();
    cin>>n;
    rep(i,1,n)cin>>a[i];
    int x=0,y=0,tag=0;
    if(!check()){
        int flag=1;
        rep(i,1,LIM)flag&=(tt[i]<=n-2);
        if(flag){
            cout<<"0\n";
            return 0;
        }
        rep(i,1,n)if(a[i]%2 && a[i]%3){
            x=i;y=(i==n)?(i-1):(i+1);
            break;
        }
        if(!x){
            rep(i,1,n)if(a[i]%2){
                x=i;
                rep(j,1,n)if(a[j]%3){
                    y=j;
                    break;
                }
                break;
            }
        }
    }else{
        rep(i,1,LIM)if(tt[i]==n){
            cnt[0]=INF;
            int A=0,B=0,p=i;
            rep(j,1,n){
                int num=a[j];cnt[j]=0;
                while(num%p==0)cnt[j]++,num/=p;
                if(cnt[j]<cnt[A])B=A,A=j;
                else if(cnt[j]<cnt[B])B=j;
            }
            x=A,y=B;
            break;
        }
    }
    S.insert(x);S.insert(y);
    rep(i,1,prime_tot)if(a[x]%prime[i]==0 || a[y]%prime[i]==0){
        int p=prime[i];
        if(p!=tag){
            cnt[0]=INF;
            int A=0,B=0;
            rep(j,1,n){
                int num=a[j];cnt[j]=0;
                while(num%p==0)cnt[j]++,num/=p;
                if(cnt[j]<cnt[A])B=A,A=j;
                else if(cnt[j]<cnt[B])B=j;
            }
            if(a[x]%p==0 && a[y]%p==0){
                S.insert(A);
                S.insert(B);
            }else{
                S.insert(B);
            }
        }
    }

    solve();

    return 0;
}