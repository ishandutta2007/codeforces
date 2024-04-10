#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
ll INF = 1e15;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define f first 
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100

vi V;
vpi comp;
vpi st,opt;
int N,a,ans,cur;

int main(){
    // freopen("in.txt","r",stdin);
    cin >>N ;
    for (int i=0;i<N;++i){cin>>a;V.pb(a);}
    sort(ALL(V));
    for (int i=0;i<N;++i){
        comp.pb(mp(V[i],1));
        while (i++, i<N){
            if (V[i] == comp.back().f)++comp.back().s;
            else {--i;break;}
        }
    }
    int T = SZ(comp);
    for (int i=0;i<T;++i){
        // cout<<"Try starting at " << comp[i].f<<'\n';
        while(SZ(st))st.pop_back();
        st.pb(comp[i]);
        cur = comp[i].s;

        while (i+1<T){
            ++i;
            if (comp[i].f - 1 != st.back().f){
                --i;
                break;
            }
            if (comp[i].s == 1){
                st.pb(comp[i]);
                cur += comp[i].s;
                --i;
                break;
            }else{
                st.pb(comp[i]);
                cur += comp[i].s;
            }
        }

        if (cur > ans){
            ans = cur;
            swap(st,opt);
        }
    }
    cout<<ans<<'\n';
    for (int x = 0;x < opt[0].s; ++x)cout<<opt[0].f<<' ';
    if(SZ(opt)==1)return 0;
    for (int i=1;i<SZ(opt)-1;++i){
        cout<<opt[i].f<<' ';
    }
    for (int x = 0;x < opt.back().s; ++x)cout<<opt.back().f<<' ';
    for (int i=SZ(opt)-2;i>=1;--i){
        for (int j=1;j<opt[i].s;++j)cout<<opt[i].f<<' ';
    }
}