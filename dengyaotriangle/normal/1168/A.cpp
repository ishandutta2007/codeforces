#include<iostream>

using namespace std;

const int maxn=300005;

int n,m;
int a[maxn];

bool chk(int d){
    int prv=0;
    for(int i=1;i<=n;i++){
        if(a[i]>prv){
            if(a[i]+d-m<prv)prv=a[i];
        }else if(a[i]<prv){
            if(a[i]+d<prv) return 0;
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=0,r=m;
    while(r-l>5){
        int mi=(l+r)/2;
        if(chk(mi))r=mi;
        else l=mi;
    }
    for(int i=l;i<=r;i++){
        if(chk(i)){
            cout<<i;
            return 0;
        }
    }
}