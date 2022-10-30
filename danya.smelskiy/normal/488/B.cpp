#include <bits/stdc++.h>
using namespace std;


int n;
int a[5];
inline void chek(int x){
    if (x<=0) return;
    int b[5];
    for (int i=1;i<=3;++i) b[i]=a[i];
    b[4]=x;
    sort(b+1,b+4+1);
    int xx=b[4]-b[1];
    int yy=(b[2]+b[3])/2;
    if ((b[2]+b[3])%2!=0) return ;
    if ((b[1]+b[2]+b[3]+b[4])%4!=0) return ;
    if ((b[1]+b[2]+b[3]+b[4])/4==xx && xx==yy) {
        cout<<"YES"<<'\n'<<x;
        exit(0);
    }
    return ;
}
inline void chek2(int x,int y){
    int b[5];
    b[1]=a[1]; b[2]=a[2]; b[3]=x; b[4]=y;
    sort(b+1,b+5);
    int xx=b[4]-b[1];
    int yy=(b[2]+b[3])/2;
    if ((b[2]+b[3])%2!=0) return ;
    if ((b[1]+b[2]+b[3]+b[4])%4!=0) return ;
    if ((b[1]+b[2]+b[3]+b[4])/4==xx && xx==yy) {
        cout<<"YES"<<'\n'<<x<<'\n'<<y;
        exit(0);
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==0) {
        cout<<"YES"<<'\n';
        cout<<1<<'\n'<<1<<'\n'<<3<<'\n'<<3;
        return 0;
    }
    if (n==1) {
        cin>>a[1];
        cout<<"YES"<<'\n';
        cout<<a[1]<<'\n'<<a[1]+a[1]+a[1]<<'\n'<<a[1]+a[1]+a[1];
        return 0;
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (n==4) {
        sort(a+1,a+n+1);
        if ((a[1]+a[2]+a[3]+a[4])%4!=0 || (a[2]+a[3])%2!=0 || (a[2]+a[3])/2!=a[4]-a[1] || (a[1]+a[2]+a[3]+a[4])/4!=a[4]-a[1]) {
            cout<<"NO";
            return 0;
        } else {
            cout<<"YES";
            return 0;
        }
    }
    if (n==3) {
        for (int i=1;i<=1500;++i)
            chek(i);
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<=1500;++i)
    for (int j=i;j<=1500;++j) {
        chek2(i,j);
    }
    cout<<"NO";
    return 0;
}