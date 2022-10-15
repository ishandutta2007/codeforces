#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
const int MAXN=1000100;

int N;
int vis[MAXN];
vi V[MAXN];
vi answer;
int iX[MAXN];

void dfs(int x,int v){
    if(v==1)answer.pb(x);
    for(auto t:V[x]){
        if(vis[t]!=-1)continue;
        vis[t]=v^1;
        dfs(t,vis[t]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;    
    if(N%2==0){
        cout<<"First\n"<<flush;
        vi A;
        N*=2;
        A.resize(N+1,0);
        int cur=1;
        int h=N/2;
        int inx=1;
        while(cur<N){
            if(A[cur]!=0)break;
            if(cur==h-1){
                A[cur]=inx;++cur;
                A[N-1]=inx;
                ++inx;
            }else if(cur==h){
                A[cur]=inx;++cur;
                A[N]=inx;
                ++inx;
            }else{
                A[cur]=A[cur+1]=inx;
                inx++;
                cur+=2;
            }
        }
        for(int i=1;i<=N;++i){            
            cout<<A[i]<<' ';
        }
        cout<<'\n'<<flush;
        int a;
        cin>>a;
        assert(a==0);
    }else{
        cout<<"Second\n"<<flush;
        for(int i=1;i<=N;++i){
            V[i].pb(i+N);
            V[i+N].pb(i);
        }
        memset(vis,-1,sizeof(vis));
        vi A;
        A.resize(N*2,-1);
        for(int i=1;i<=2*N;++i){
            int a;cin>>a;
            // iX[i]=a;
            if(A[a]==-1){
                A[a]=i;
                continue;
            }else{
                V[i].pb(A[a]);
                V[A[a]].pb(i);
            }
        }
        for(int i=1;i<=2*N;++i){
            if(vis[i]!=-1)continue;
            vis[i]=1;
            dfs(i,1);
        }
        ll S=0;
        for(auto i:answer)S+=i;
        if(S%(2*N) != 0){
            for(auto &i:answer){
                if(i>N)i-=N;
                else i+=N;
            }
        }
        sort(ALL(answer));

        for(auto i:answer)cout<<i<<' ';cout<<'\n';
        // for(auto i:answer)cout<<iX[i]<<' ';cout<<'\n';
        cout<<flush;
    }
}