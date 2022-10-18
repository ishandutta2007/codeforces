#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

int n;
int x[maxn];
int ex,ey;
int pfx[maxn],pfy[maxn];

char _[maxn];

int absl(int a){
    return (a<0?-a:a);
}

bool chk(int v){
    for(int i=1;i<=n-v+1;i++){
        int q=v-absl(pfx[n]-pfx[i+v-1]+pfx[i-1]-ex)-absl(pfy[n]-pfy[i+v-1]+pfy[i-1]-ey);
        if(q>=0&&q%2==0){
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    cin>>_;
    for(int i=1;i<=n;i++){
        switch(_[i-1]){
            case 'U': x[i]=0;break;
            case 'D': x[i]=1;break;
            case 'L': x[i]=2;break;
            case 'R': x[i]=3;break;
        }
    }
    cin>>ex>>ey;
    for(int i=1;i<=n;i++){
        pfx[i]=pfx[i-1]+dx[x[i]];
        pfy[i]=pfy[i-1]+dy[x[i]];
    }
    int l=0,r=n;
    while(r-l>3){
        int m=(l+r)>>1;
        if(chk(m)){
            r=m;
        }else{
            l=m;
        }
    }
    for(int i=l;i<=r;i++){
        if(chk(i)){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}