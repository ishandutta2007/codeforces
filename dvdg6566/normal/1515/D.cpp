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

const int MAXN=2e5+100;

int xx,N,Q,a,b,c,d,e,K,M,A,B;
pi L[MAXN];

int main(){
    cin>>xx;
    while(xx--){
        cin>>N>>A>>B;
        for(int i=0;i<=N;++i)L[i].f=L[i].s=0;
        for(int i=0;i<A;++i){cin>>a;L[a].f++;}
        for(int i=0;i<B;++i){cin>>a;L[a].s++;}
        for(int i=0;i<=N;++i){
            int a=min(L[i].f,L[i].s);
            L[i].f-=a;L[i].s-=a;
        }
        int l=0;
        int r=0;
        for(int i=0;i<=N;++i){
            l+=L[i].f;
            r+=L[i].s;
        }
        int ans=0;
        if(r>l){
            // clear r
            int e=abs(l-r);
            for(int i=0;i<=N;++i)if(e){
                while(L[i].s>1&&e){
                    L[i].s-=2;
                    e-=2;
                    r-=2;
                    ++ans;
                }
            }
        }else{
            int e=abs(l-r);
            for(int i=0;i<=N;++i)if(e){
                while(L[i].f>1&&e){
                    L[i].f-=2;
                    e-=2;
                    l-=2;
                    ++ans;
                }
            }
        }
        // cerr<<l<<' '<<r<<'\n';
        int d=abs(l-r);
        ans+=d;
        ans+=min(l,r);
        cout<<ans<<'\n';
    }
}