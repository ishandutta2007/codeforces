#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb emplace_back
#define f first 
#define s second
#define mp make_pair
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

const ll MAXN = 1e5;

ll a,b,c,T,N,K;
ll A[MAXN];

int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1;i<=N;++i)cin>>A[i];
        int me=1;
        for(int i=2;i<=N;++i)if(A[i]<A[me])me=i;
        cout<<N-1<<'\n';
        for(int i=1;i<=N;++i)if(i!=me){
            int nv=abs(i-me)+A[me];
            cout<<i<<' '<<me<<' '<<nv<<' '<<A[me]<<'\n';
            A[i]=nv;
        }
        // cerr<<"DB: ";for(int i=1;i<=N;++i)cerr<<A[i]<<' ';cerr<<'\n';
    }
}