#include<bits/stdc++.h>
using namespace std;

typedef __int128_t solong;

struct vec{
    solong x,y;
    vec(solong x=0,solong y=0):x(x),y(y){}
    vec operator+(const vec &a)const{return vec(x+a.x,y+a.y);}
    vec operator-(const vec &a)const{return vec(x-a.x,y-a.y);}
};

solong cross(const vec &a,const vec &b){
    return a.x*b.y-a.y*b.x;
}

int n;
vec a[1000005],c[1000005];
solong b[1000005];

solong area(int i,int j){//i<=j
    return b[j]-b[i]+cross(a[j],a[i]);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[i]=vec(x,y);
    }
    reverse(a+1,a+1+n);
    for(int i=1;i<=2*n;i++){
        a[i]=i>n?a[i-n]:a[i];
        b[i]=b[i-1]+cross(a[i-1],a[i]);
        c[i]=c[i-1]+a[i];
    }
    solong tot=area(1,n),ans=tot*n*(n-3)/2,sum=0;
    int cnt=0;
    for(int l=1,r=1;l<=n;l++){
        solong tmp;
        while(2*(tmp=area(l,r+1))<=tot){
            r++;
            sum+=tmp;
            cnt+=2*tmp==tot;
        }
        ans-=2*sum;
        sum-=cross(a[l],a[l+1])*(r-l);
        sum+=cross(c[r]-c[l],a[l+1]-a[l]);
    }
    ans+=cnt/2*tot;
    cout<<int(ans%1000000007)<<'\n';

    return 0;
}