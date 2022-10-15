#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end() 
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN=200100;
const ll MOD=998244353;

int A[MAXN];
map<int,int> M;
int Q;

pi ask(int s,int e){
    cout<<"? "<<s<<' '<<e<<'\n';
    cout<<flush;
    int a,b;
    cin>>a>>b;
    return mp(a,b);
    // ++Q;
    // M.clear();
    // for(int i=s;i<=e;++i){
    //     M[A[i]]++;
    // }
    // int ans=M.begin()->f;
    // for(auto i:M){
    //     if(i.s>M[ans])ans=i.f;
    // }
    // // cerr<<"Asnwer "<<ans<<' '<<M[ans]<<'\n';
    // return mp(ans,M[ans]);
}

map<pi,pi> svQ;

pi query(int s,int e){
    if(svQ[mp(s,e)].f!=0)return svQ[mp(s,e)];
    return svQ[mp(s,e)]=ask(s,e);
}

int ans[MAXN];
const pi Z=mp(0,0);

void dnc(int s,int e){
    // cerr<<"Dnc "<<s<<' '<<e<<'\n';
    if(e-s<=1){
        ans[s]=query(s,s).f;
        if(ans[e]==0)ans[e]=query(e,e).f;
        return;
    }
    int a=query(s,s).f;
    int b=query(e,e).f;
    if(a==b){
        for(int i=s;i<=e;++i)ans[i]=a;
        return;
    }
    pi c;
    c=query(s,e);
    if(c.f==a){
        for(int i=s;i<s+c.s;++i)ans[i]=c.f;
        dnc(s+c.s,e);
        return;
    }
    if(c.f==b){
        for(int i=e;i>e-c.s;--i)ans[i]=c.f;
        dnc(s,e-c.s);
        return;
    }

    int m=(s+e)/2;
    int mid=query(m,m).f;
    if(c.f==mid){
        dnc(s,m);
        int rep=0;
        for(int i=s;i<=m;++i)if(ans[i]==mid)++rep;
        int ept=m+1+c.s-rep;
        for(int i=m+1;i<ept;++i)ans[i]=mid;
        dnc(ept,e);
        return;
    }

    if(c.f>mid){
        dnc(s,m);
        dnc(m,e);
    }else{
        dnc(s,m);
        dnc(m,e);
    }
}

int main(){
    int N;
    cin>>N;
    // for(int i=1;i<=N;++i)cin>>A[i];
    

    dnc(1,N);
    cout<<"! ";
    for(int i=1;i<=N;++i)cout<<ans[i]<<' ';cout<<'\n';
    cout<<flush;
    // cout<<Q<<'\n';
}