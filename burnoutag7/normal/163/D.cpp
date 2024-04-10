#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll V,v,vv;
vector<pair<ll,int>> p;

ll S(ll a,ll b,ll c){
    return 2*(a*b+a*c+b*c);
}

ll ansS,ansa,ansb,ansc;

void upd(ll a,ll b,ll c){
    if(ansS>S(a,b,c)){
        ansS=S(a,b,c);
        ansa=a;
        ansb=b;
        ansc=c;
    }
}

void dsf(int n,ll a,ll b){
    if(b>vv)return;
    if(n==p.size()){
        upd(a,b,V/a/b);
        return;
    }
    for(int i=0;i<=p[n].second;i++){
        if(i)b*=p[n].first;
        dsf(n+1,a,b);
    }
}

void fixa(ll a){
    ll tmp=a;
    for(pair<ll,int> &i:p)while(tmp%i.first==0){
        tmp/=i.first;
        i.second--;
    }
    int l=1,r=1000000000,m;
    while(l<=r){
        m=l+r>>1;
        if((ll)m*m<=V/a){
            l=m+1;
            vv=m;
        }else{
            r=m-1;
        }
    }
    dsf(0,a,1);
    tmp=a;
    for(pair<ll,int> &i:p)while(tmp%i.first==0){
        tmp/=i.first;
        i.second++;
    }
}

void dfs(int n,ll a){
    if(a>v)return;
    if(n==p.size()){
        if((double)2*V/a+(double)4*a*sqrt((double)V/a)<=ansS)fixa(a);
        return;
    }
    for(int i=0;i<=p[n].second;i++){
        if(i)a*=p[n].first;
        dfs(n+1,a);
    }
}

void mian(){
    ansS=5e18;
    int n;
    cin>>n;
    p.resize(n);
    V=1;
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
        for(int j=0;j<p[i].second;j++)V*=p[i].first;
    }
    int l=1,r=1000000,m;
    while(l<=r){
        m=l+r>>1;
        if((ll)m*m*m<=V){
            l=m+1;
            v=m;
        }else{
            r=m-1;
        }
    }
    dfs(0,1);
    cout<<ansS<<' '<<ansa<<' '<<ansb<<' '<<ansc<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}