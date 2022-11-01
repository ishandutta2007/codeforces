#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,x[1005],y[1005];
ll px[1005],sx[1005],py[1005],sy[1005];
vector<int> vx,vy;

void mian(){
    cin>>n;
    vx.clear();
    vy.clear();
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    px[1]=py[1]=sx[n]=sy[n]=0;
    for(int i=2;i<=n;i++){
        px[i]=px[i-1]+(ll)(i-1)*(vx[i-1]-vx[i-2]);
        py[i]=py[i-1]+(ll)(i-1)*(vy[i-1]-vy[i-2]);
    }
    for(int i=n-1;i>=1;i--){
        sx[i]=sx[i+1]+(ll)(n-i)*(vx[i]-vx[i-1]);
        sy[i]=sy[i+1]+(ll)(n-i)*(vy[i]-vy[i-1]);
    }
    int lx=1e9,rx=0,ly=1e9,ry=0;
    ll mn=1e18;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        int xp=upper_bound(vx.begin(),vx.end(),x[i])-vx.begin(),yp=upper_bound(vy.begin(),vy.end(),y[j])-vy.begin();
        mn=min(mn,px[xp]+sx[xp]+py[yp]+sy[yp]);
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        int xp=upper_bound(vx.begin(),vx.end(),x[i])-vx.begin(),yp=upper_bound(vy.begin(),vy.end(),y[j])-vy.begin();
        if(mn==px[xp]+sx[xp]+py[yp]+sy[yp]){
            lx=min(lx,x[i]);
            rx=max(rx,x[i]);
            ly=min(ly,y[j]);
            ry=max(ry,y[j]);
        }
    }
    cout<<(ll)(rx-lx+1)*(ry-ly+1)<<'\n';
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