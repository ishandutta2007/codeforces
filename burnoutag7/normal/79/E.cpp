#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int n,a,b,c,x[4],y[4];
//   T
// 23
// 01
//S
ll t[4];

bool square(int px,int py){
    if(*min_element(t,t+4)<0)return false;
    ll l,r,s;
    s=2ll*c*(a+c-px+b+c-py);
    l=(a+c-px+1ll)*(a+c-px)/2+(ll)(py-b)*(a+c-px)+(py-b+c-1ll)*(b+c-py)/2;
    r=(py-b+c-1ll)*(b+c-py)/2+(ll)(a+c-px)*(b+c-py)+(a+c-px+1ll)*(a+c-px)/2+(ll)c*(a+c-px);
    return t[1]-(l&1^t[1]&1)>=l&&t[2]-(s-r&1^t[2]&1)>=s-r;
}

bool reach(int px,int py){
    if(px>n||py>n||*min_element(t,t+4)<0)return false;
    if(px==n&&py==n){
        for(int i=0;i<4;i++)if(t[i]<dis(n,n,x[i],y[i]))return false;
        return true;
    }
    int tx=px<a?0:px<a+c?1:2,ty=py<b?0:py<b+c?1:2;
    if(tx==0){//a->px
        ll dt[4],d=a-px;
        dt[0]=(1+d)*d/2+abs(py-b)*d;dt[1]=dt[0]+c*d;
        dt[2]=(1+d)*d/2+abs(b+c-py)*d;dt[3]=dt[2]+c*d;
        for(int i=0;i<4;i++)t[i]-=dt[i];
        bool res=reach(a,py);
        for(int i=0;i<4;i++)t[i]+=dt[i];
        return res;
    }
    if(ty==0){//b->py
        ll dt[4],d=b-py;
        dt[0]=(1+d)*d/2+abs(px-a)*d;dt[2]=dt[0]+c*d;
        dt[1]=(1+d)*d/2+abs(a+c-px)*d;dt[3]=dt[1]+c*d;
        for(int i=0;i<4;i++)t[i]-=dt[i];
        bool res=reach(px,b);
        for(int i=0;i<4;i++)t[i]+=dt[i];
        return res;
    }
    if(tx==1&&ty==1){//a+c->px,b+c->py
        ll dt[4],d=n-a-c+n-b-c+1;
        dt[3]=(n-a-c+n-b-c)*d/2;
        dt[1]=dt[2]=dt[3]+c*d;
        dt[0]=dt[1]+c*d;
        dt[0]+=(ll)(px-a+py-b+c*2-1)*(a+c-px+b+c-py)/2;
        dt[3]+=(ll)(a+c-px+b+c-py+1)*(a+c-px+b+c-py)/2;
        for(int i=0;i<4;i++)t[i]-=dt[i];
        bool res=square(px,py);
        for(int i=0;i<4;i++)t[i]+=dt[i];
        return res;
    }
    if(tx==1){//a+c->px
        ll dt[4],d=a+c-px;
        dt[2]=(px-a+c-1)*d/2+abs(b+c-py)*d;dt[0]=dt[2]+c*d;
        dt[3]=(1+d)*d/2+abs(b+c-py)*d;dt[1]=dt[3]+c*d;
        for(int i=0;i<4;i++)t[i]-=dt[i];
        bool res=reach(a+c,py);
        for(int i=0;i<4;i++)t[i]+=dt[i];
        return res;
    }
    if(ty==1){//b+c->py
        ll dt[4],d=b+c-py;
        dt[1]=(py-b+c-1)*d/2+abs(a+c-px)*d;dt[0]=dt[1]+c*d;
        dt[3]=(1+d)*d/2+abs(a+c-px)*d;dt[2]=dt[3]+c*d;
        for(int i=0;i<4;i++)t[i]-=dt[i];
        bool res=reach(px,b+c);
        for(int i=0;i<4;i++)t[i]+=dt[i];
        return res;
    }
    ll dt[4],d=n-px+n-py+1;
    dt[3]=(px-a-c+py-b-c+n-a-c+n-b-c)*d/2;
    dt[1]=dt[2]=dt[3]+c*d;
    dt[0]=dt[1]+c*d;
    for(int i=0;i<4;i++)if(t[i]<dt[i])return false;
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>t[0]>>a>>b>>c;
    c--;
    t[1]=t[2]=t[3]=t[0];
    x[0]=x[2]=a,x[1]=x[3]=a+c;
    y[0]=y[1]=b,y[2]=y[3]=b+c;
    if(!reach(2,1)&&!reach(1,2)){
        cout<<"Impossible\n";
        return 0;
    }
    int px=1,py=1;
    while(px!=n||py!=n){
        if(reach(px+1,py)){
            cout<<'R';
            px++;
        }else{
            cout<<'U';
            py++;
        }
        for(int i=0;i<4;i++)t[i]-=dis(x[i],y[i],px,py);
    }

    return 0;
}