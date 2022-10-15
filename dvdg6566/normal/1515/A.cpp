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

int T,N,Q,a,b,c,d,e,K;
vi V,A;

int main(){
    cin>>T;
    while(T--){
        cin>>N>>K;
        A.clear();V.clear();
        for(int i=1;i<=N;++i){cin>>a;V.pb(a);}
        sort(ALL(V));
        int w=0;
        for(auto i:V)w+=i;
        if(w==K){
            cout<<"NO\n";
            continue;
        }

        ll c=0;
        ll flag=-1;
        for(int i=0;i<N;++i){
            c+=V[i];
            if(c==K)flag=i;
        }
        if(flag!=-1)swap(V[flag],V.back());
        cout<<"YES\n";
        for(auto i:V)cout<<i<<' ';cout<<'\n';
    }
}