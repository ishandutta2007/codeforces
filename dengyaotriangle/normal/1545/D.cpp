#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1005;

int n,k;
int a[maxn][maxn];
long long sm[maxn],sm2[maxn];
int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++)cin>>a[i][j],sm[i]+=a[i][j],sm2[i]+=a[i][j]*(long long)a[i][j];
    }
    long long dif=(sm[k-1]-sm[0])/(k-1);
    int pos;
    for(int i=0;i<k;i++){
        if(sm[i]-sm[0]!=i*dif){
            pos=i;
        }
    }
    long long ha,hb,hc;int p;
    if(pos<3){
        p=pos-3;
        ha=sm2[3],hb=sm2[4],hc=sm2[5];
    }else{
        p=pos;
        ha=sm2[0],hb=sm2[1],hc=sm2[2];
    }
    long long res=(ha*2+(4*hb-3*ha-hc)*p+(hc-2*hb+ha)*p*p)/2;
    long long cdif=sm[pos]-sm[0]-pos*dif,qdif=sm2[pos]-res;
    long long ans=(qdif-cdif*cdif)/(2*cdif);
    cout<<pos<<' '<<ans;
    return 0;
}