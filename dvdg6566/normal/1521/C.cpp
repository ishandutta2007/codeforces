#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef long long ll;
#define pb emplace_back
#define f first 
#define s second
#define mp make_pair
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

const int MAXN = 1e5;

int a,b,c,T,N,K;
int A[MAXN];

int p[MAXN];
int ans[MAXN];
int XXX;

int query(int t, int i, int j, int x){
    ++XXX;
    cout<<"? "<<t<<' '<<i<<' '<<j<<' '<<x<<endl;
    int res;cin>>res;
    return res;
    if (t==1){
        return max(min(x,p[i]), min(x+1,p[j]));
    }else{
        return min(max(x,p[i]), max(x+1,p[j]));
    }
}

pi find_val(int s,int e){
    int higher = max(query(1,s,e,N-1), query(1,e,s,N-1));
    int lower = min(query(2,s,e,1), query(2,e,s,1));
    // cerr<<lower<<' '<<higher<<'\n';
    // S and E map to lower and higher in some order
    if(query(2,s,e,lower) == lower+1){
        swap(lower,higher);
    }
    return mp(lower,higher);
}

void filllow(){
    int W=0;
    for(int i=1;i<=N;++i)if(ans[i]==-1){
        int k=query(1,1,i,N-1);
        if(k>ans[1]&&k<N-1){
            ans[i]=k;
            ++W;
        }
    }
    // cerr<<"L "<<W<<'\n';
}

void fillhigh(){
    int W=0;
    for(int i=1;i<=N;++i)if(ans[i]==-1){
        int k=query(2,1,i,1);
        if(k<ans[1]&&k>2){
            ans[i]=k;
            ++W;
        }
    }
    // cerr<<"H "<<W<<'\n';
}

int main(){
    cin>>T;
    while(T--){
        cin>>N;
        // for(int i=1;i<=N;++i)cin>>p[i];
        int s=1;
        int e=N;
        for(int i=1;i<=N;++i)ans[i]=-1;
        pi t=find_val(s,e);
        ans[s]=t.f;
        ans[e]=t.s;
        // cerr<<t.f<<' '<<t.s<<'\n';
        // assert(t.f==p[s]);
        // assert(t.s==p[e]);
        // return 0;

        int tar=ans[s];

        if(N/2 < tar){
            // fill the 
            fillhigh();
            filllow();
        }else{
            filllow();
            fillhigh();
        }

        vi leftovers;
        for(int i=1;i<=N;++i)if(ans[i]==-1)leftovers.pb(i);

        if(SZ(leftovers)%2==1)leftovers.pb(1);
        for(int i=0;i<SZ(leftovers);i+=2){
            int a=leftovers[i];
            int b=leftovers[i+1];
            pi t=find_val(a,b);
            ans[a]=t.f;
            ans[b]=t.s;
        }

        cout<<"! ";for(int i=1;i<=N;++i)cout<<ans[i]<<' ';cout<<endl;
    }
    // cerr<<XXX<<'\n';
}