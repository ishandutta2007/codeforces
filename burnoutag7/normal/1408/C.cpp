#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005];

void mian(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    a[n]=m-a[n-1];
    for(int i=n-1;i>0;i--)a[i]-=a[i-1];
    n++;
    int l=0,r=n,vl=1,vr=1;
    double t=0,dl=0,dr=0;
    while(l+1<r){
        if((a[l]-dl)*vr<=(a[r-1]-dr)*vl){
            dr+=(a[l]-dl)/vl*vr;
            t+=(a[l]-dl)/vl;
            dl=0;
            l++;
            vl++;
        }else{
            dl+=(a[r-1]-dr)/vr*vl;
            t+=(a[r-1]-dr)/vr;
            dr=0;
            r--;
            vr++;
        }
    }
    t+=(double)(a[l]-dl-dr)/(vl+vr);
    cout<<t<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout<<fixed<<setprecision(10);
    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}