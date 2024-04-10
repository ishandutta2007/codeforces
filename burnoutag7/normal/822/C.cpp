#include<bits/stdc++.h>
using namespace std;

struct voucher{
    int l,r,cost,duration;
}a[200005];

bool cmp1(voucher i,voucher j){
    return i.r<j.r;
}

int n,x;
vector<voucher> v[200005];
vector<int> f[200005];
int ans;

int func(voucher fd){
    int l=0,r=v[fd.duration].size()-1,m,res=-1;
    while(l<=r){
        m=(l+r)/2;
        if(v[fd.duration][m].r<fd.l){
            l=m+1;
            res=m;
        }else{
            r=m-1;
        }
    }
    return (res==-1?2000000001:f[fd.duration][res]+fd.cost);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r>>a[i].cost;
        a[i].duration=a[i].r-a[i].l+1;
    }
    ans=2000000001;
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++){
        if(a[i].duration>=x)continue;
        ans=min(ans,func(a[i]));
        v[x-a[i].duration].push_back(a[i]);
        f[x-a[i].duration].push_back(min(int(f[x-a[i].duration].empty()?1e9:f[x-a[i].duration].back()),a[i].cost));
    }
    if(ans==2000000001){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

    return 0;
}