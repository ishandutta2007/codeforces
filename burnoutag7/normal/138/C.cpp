#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005],b[10005],h[100005],l[100005],r[100005],z[10005],zcnt[10005];
double dat[10005];
vector<int> vx;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>h[i]>>l[i]>>r[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i]>>z[i];
        vx.emplace_back(b[i]);
    }
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    fill(dat,dat+vx.size()+1,1);
    for(int i=1;i<=n;i++){
        int ll=lower_bound(vx.begin(),vx.end(),a[i]-h[i])-vx.begin()+1;
        int lr=upper_bound(vx.begin(),vx.end(),a[i]-1)-vx.begin();
        int rl=lower_bound(vx.begin(),vx.end(),a[i]+1)-vx.begin()+1;
        int rr=upper_bound(vx.begin(),vx.end(),a[i]+h[i])-vx.begin();
        if(ll<=lr){
            if(l[i]==100){
                zcnt[ll]++;
                zcnt[lr+1]--;
            }else{
                dat[ll]*=1-l[i]/100.0;
                dat[lr+1]/=1-l[i]/100.0;
            }
        }
        if(rl<=rr){
            if(r[i]==100){
                zcnt[rl]++;
                zcnt[rr+1]--;
            }else{
                dat[rl]*=1-r[i]/100.0;
                dat[rr+1]/=1-r[i]/100.0;
            }
        }
    }
    for(int i=1;i<=vx.size();i++){
        dat[i]*=dat[i-1];
        zcnt[i]+=zcnt[i-1];
    }
    for(int i=1;i<=vx.size();i++)if(zcnt[i])dat[i]=0;
    double ans=0;
    for(int i=1;i<=m;i++){
        ans+=dat[upper_bound(vx.begin(),vx.end(),b[i])-vx.begin()]*z[i];
    }
    cout<<fixed<<setprecision(5)<<ans;

    return 0;
}