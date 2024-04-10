#include <bits/stdc++.h>

using namespace std;

#define DIM 1000009
#define INF ((int)1e9+9ll)
#define pairll pair<int,int>
#define fi first
#define se second
#define ld long double
#define amen exit(0)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define MODULO 1000000007
#define BLOCK 1001

int i,j,k,l,n,m,kilk,res=INF,sz;

vector<int>a[DIM];

int vis[DIM],can[DIM],dist[DIM],par[DIM];

int mp[DIM];

unordered_set<long long>st;

queue<int>q;

void count3(int start){
    memset(dist,-1,sizeof(dist));
    memset(par,0,sizeof(par));

    dist[start]=0;
    q.push(start);
    while(!q.empty()){
        k=q.front();

        q.pop();

        for(auto to:a[k]){
            if(dist[to]==-1){
                dist[to]=dist[k]+1;
                par[to]=k;
                q.push(to);
            }
            else{
                if(par[k]!=to)res=min(res,dist[k]+dist[to]+1);
            }
        }
    }
}

int main()
{   
    fast;

    for(long long i=2;i<DIM;i++){
        if(vis[i]==0){
            k=++sz;
            mp[i]=k;
            vis[i]=i;
            for(long long j=i*i;j<DIM;j+=i){
                if(vis[j]==0)vis[j]=i;
            }
        }
    }

    sz++;

    cin>>n;
    for(i=1;i<=n;i++){
        cin>>k;
        l=sqrt(k);

        if(l*l==k)return cout<<1<<endl,0;
        
        l=vis[k];
        int cnt=0;
        while(k%l==0){
            cnt++;
            k/=l;
        }

        int v=0,u=0;
        if(cnt%2==1)v=l;

        cnt=0;

        if(k>1){
            l=vis[k];
            while(k%l==0){
                cnt++;
                k/=l;
            }

            if(cnt%2==1)u=l;
        }

        if(u!=0 && v!=0){
            a[mp[u]].push_back(mp[v]);
            a[mp[v]].push_back(mp[u]);
            if(st.count((long long)u*DIM+(long long)v))res=2;
            if(st.count((long long)v*DIM+(long long)u))res=2;
            st.insert((long long)u*DIM+(long long)v);
        }

        if(u==0){
            can[mp[v]]++;
            if(can[mp[v]]==1)kilk++;
            a[mp[v]].push_back(sz);
            a[sz].push_back(mp[v]);
            if(can[mp[v]]>1)res=2;
        }
        if(v==0){
            can[mp[u]]++;
            if(can[mp[u]]==1)kilk++;
            a[mp[u]].push_back(sz);
            a[sz].push_back(mp[u]);
            if(can[mp[u]]>1)res=2;
        }
    }

    if(res<3)return cout<<res<<endl,0;

    for(i=2;i<=1000;i++){
        if(vis[i]==i)count3(mp[i]);
    }

    if(res==INF)return cout<<-1<<endl,0;

    cout<<res<<endl;

    amen;
}