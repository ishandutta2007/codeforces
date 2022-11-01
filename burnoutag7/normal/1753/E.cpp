#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,b,p,m,a[1000005],lc,totm=1,C=1;
ll ppa[1000005];
char op[1000005];
vector<int> vm;
vector<pair<int,int>> vp;
vector<ll> sp;
vector<int> rm;
vector<bool> am;

pair<int,ll> check(int i,ll po){
    int l=0,r=vp[i].second-vp[i].first,mid,resi=0;
    ll resl=0;
    while(l<=r){
        mid=l+r>>1;
        if((ll)a[vp[i].first+mid]*(totm-rm[i])>=po){
            resi=mid+1;
            resl=(ppa[vp[i].first+mid]-ppa[vp[i].first-1])*(totm-rm[i]);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return {resi,resl};
}

ll solve(int lb){
    lb/=p;
    ll ans=0;
    for(int i=0;i<lc;i++)if(am[i]){
        ll cur=sp[i];
        for(int j=0;j<i;j++)if(am[j])cur*=a[vm[j]];
        ans+=cur;
    }
    rm.assign(lc+1,1);
    for(int i=0,pp=1;i<=lc;i++){
        if(i&&am[i-1])pp*=a[vm[i-1]];
        rm[i]*=pp;
    }
    for(int i=lc,pp=1;i>=0;i--){
        if(i<lc)pp*=a[vm[i]];
        rm[i]*=pp;
    }
    ll l=0,r=4e18,mid,res,resp;
    int resb;
    while(l<=r){
        mid=l+r>>1;
        int ub=0;
        ll totp=0;
        for(int i=0;i<=lc&&ub<=lb;i++){
            auto rp=check(i,mid);
            ub+=rp.first;
            totp+=rp.second;
        }
        if(ub<=lb){
            res=mid;
            resb=ub;
            resp=totp;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    lb-=resb;
    ans+=resp;
    int cnt=0;
    if(res)for(int i=0;i<=lc;i++){
        auto rp=check(i,res);
        if(rp.first<vp[i].second-vp[i].first+1){
            cnt+=check(i,res-1).first-rp.first;
        }
    }
    return ans+(res-1)*min(lb,cnt);
}

ll dfs(int d,int prvu,int lb){
    if(d==lc){
        return solve(lb);
    }
    am[d]=0;
    ll res=dfs(d+1,max(prvu,a[vm[d]]),lb);
    if(prvu<a[vm[d]]&&lb>=m){
        am[d]=1;
        res=max(res,dfs(d+1,prvu,lb-m));
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>b>>p>>m;
    {
        int j=1;
        for(int i=1;i<=n;i++){
            cin>>op[i]>>a[i];
            if(op[i]=='*')if(a[i]==1){
                i--;
                n--;
            }else{
                vm.emplace_back(i);
                totm*=a[i];
                vp.emplace_back(j,i-1);
                j=i+1;
                C*=a[i];
            }else{
                C+=a[i];
            }
        }
        am.resize(lc=vm.size());
        vp.emplace_back(j,n);
        rm.resize(lc+1);
        sp.resize(lc);
    }
    for(int i=0;i<=lc;i++){
        sort(a+vp[i].first,a+vp[i].second+1);
        reverse(a+vp[i].first,a+vp[i].second+1);
    }
    for(int i=1;i<=n;i++)ppa[i]=ppa[i-1]+a[i];
    for(int i=0;i<lc;i++){
        for(int j=i;j<lc;j++){
            sp[i]=sp[i]*a[vm[j]]+accumulate(a+vp[j+1].first,a+vp[j+1].second+1,0);
        }
        sp[i]*=a[vm[i]]-1;
    }
    cout<<dfs(0,1,b)+C<<'\n';

    return 0;
}