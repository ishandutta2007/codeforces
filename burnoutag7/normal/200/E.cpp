#include<bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1;y=0;
        return a;
    }
    int g=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}

int n,s,c[3],ans[3],k[3],x,y,g;
bool fst=1;

void upd(){
    if(k[0]>=0&&k[1]>=k[0]&&k[2]>=k[1]&&c[0]*k[0]+c[1]*k[1]+c[2]*k[2]==s){
        if(fst||abs(c[0]*k[0]-c[1]*k[1])+abs(c[2]*k[2]-c[1]*k[1])<abs(ans[0]*c[0]-ans[1]*c[1])+abs(ans[2]*c[2]-ans[1]*c[1])){
            memcpy(ans,k,12);
            fst=0;
        }
    }
}

void deal(double l,double r){
    if(l-1>r)return;
    int sum=s-k[0]*c[0];
    while(l+2<=r){
        double m1=(l*2+r)/3,m2=(l+r*2)/3,v1[3]={0,m1,(sum-m1*c[1])/c[2]},v2[3]={0,m2,(sum-m2*c[1])/c[2]};
        auto eval=[&](double *v){
            return abs(k[0]*c[0]-v[1]*c[1])+abs(v[2]*c[2]-v[1]*c[1]);
        };
        if(eval(v1)<=eval(v2)){
            r=m1;
        }else{
            l=m2;
        }
    }
    k[1]=sum/g*x;
    k[2]=sum/g*y;
    int step=(int)(l-k[1])/(c[2]/g)+10;
    k[1]+=c[2]/g*step;
    k[2]-=c[1]/g*step;
    for(int i=0;i<=20;i++){
        upd();
        k[1]-=c[2]/g;
        k[2]+=c[1]/g;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        c[t-3]++;
    }
    g=exgcd(c[1],c[2],x,y);
    for(k[0]=0;k[0]*n<=s;k[0]++){
        int sum=s-k[0]*c[0];
        if(sum%g)continue;
        double lb=k[0],rb=(double)sum/(c[1]+c[2]);
        {//0>1 1>2
            double l=lb,r=rb;
            r=min(r,(double)k[0]*c[0]/c[1]);
            l=max(l,(double)sum/2/c[1]);
            deal(l,r);
        }
        {//0<1 1>2
            double l=lb,r=rb;
            l=max(l,(double)k[0]*c[0]/c[1]);
            l=max(l,(double)sum/2/c[1]);
            deal(l,r);
        }
        {//0>1 1<2
            double l=lb,r=rb;
            r=min(r,(double)k[0]*c[0]/c[1]);
            r=min(r,(double)sum/2/c[1]);
            deal(l,r);
        }
        {//0<1 1<2
            double l=lb,r=rb;
            l=max(l,(double)k[0]*c[0]/c[1]);
            r=min(r,(double)sum/2/c[1]);
            deal(l,r);
        }
    }
    if(fst)cout<<"-1\n";
    else cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';

    return 0;
}