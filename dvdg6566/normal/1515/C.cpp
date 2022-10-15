#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define f first 
#define s second
#define mp make_pair
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

const int MAXN=1e5+100;

int xx,N,Q,a,b,c,d,e,K,M;
vpi A;
vpi T;
int ans[MAXN];

int main(){
    cin>>xx;
    while(xx--){
        cin>>N>>M>>K;
        A.clear();
        for(int i=1;i<=N;++i){
            cin>>a;
            A.pb(a,i);
        }
        sort(ALL(A)); // biggest at the back
        T.clear();
        for(int i=1;i<=M;++i)T.pb(0,i);
        while(SZ(A)){
            sort(ALL(T));
            // biggest at the back, smallest in front
            for(int i=0;i<M;++i)if(SZ(A)){
                pi w=A.back();A.pop_back();
                pi n=T[i];
                ans[w.s]=n.s;
                n.f+=w.f;
            }
        }
        cout<<"YES\n";
        for(int i=1;i<=N;++i)cout<<ans[i]<<' ';cout<<'\n';
    }
}