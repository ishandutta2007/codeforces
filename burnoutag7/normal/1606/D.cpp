#include<bits/stdc++.h>
using namespace std;

struct row{
    int pmx,pmn,smx,smn,id;
    row(){
        pmx=pmn=smx=smn=id=0;
    }
    row(int _pmx,int _pmn,int _smx,int _smn,int _id){
        pmx=_pmx;pmn=_pmn;smx=_smx;smn=_smn;id=_id;
    }
    bool operator<(const row &a)const{
        if(pmn!=a.pmn)return pmn<a.pmn;
        return id<a.id;
    }
};

int n,m;
vector<int> a[500005],pmx[500005],pmn[500005],smx[500005],smn[500005];
row rs[500005];
char ans[500005];
multiset<int> sm;

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i].assign(m+2,0);
        pmx[i].assign(m+2,0);
        pmn[i].assign(m+2,1e9);
        smx[i].assign(m+2,0);
        smn[i].assign(m+2,1e9);
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            pmx[i][j]=max(pmx[i][j-1],a[i][j]);
            pmn[i][j]=min(pmn[i][j-1],a[i][j]);
        }
        for(int j=m;j>=1;j--){
            smx[i][j]=max(smx[i][j+1],a[i][j]);
            smn[i][j]=min(smn[i][j+1],a[i][j]);
        }
    }
    for(int k=1;k<m;k++){
        sm.clear();
        for(int i=1;i<=n;i++){
            rs[i]=row(pmx[i][k],pmn[i][k],smx[i][k+1],smn[i][k+1],i-1);
            sm.emplace(smx[i][k+1]);
        }
        memset(ans,'R',n);
        ans[n]='\0';
        sort(rs+1,rs+1+n);
        int pmax=0,smin=1e9;
        for(int i=1;i<n;i++){
            //move row i to blue
            pmax=max(pmax,rs[i].pmx);
            smin=min(smin,rs[i].smn);
            sm.erase(sm.find(rs[i].smx));
            ans[rs[i].id]='B';
            int smax=*sm.rbegin(),pmin=rs[i+1].pmn;
            if(pmin>pmax&&smax<smin){
                cout<<"YES\n"<<ans<<" "<<k<<"\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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