#include<bits/stdc++.h>
using namespace std;

int n,m,a[400005],b[400005];

void mian(){
    cin>>n;
    m=n%4?n*3/4+1:n*3/4;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+1+n);
    reverse(b+1,b+1+n);
    int sum=0;
    for(int i=n-m+1;i<=n;i++)sum+=a[i];
    for(int i=1;i<=m;i++)sum-=b[i];
    int nn=n;
    while(sum<0){
        a[++nn]=100;
        b[nn]=0;
        sum+=100;
        if((nn%4?nn*3/4+1:nn*3/4)==m){
            sum-=a[nn-m];
        }else{
            sum-=b[++m];
        }
    }
    cout<<nn-n<<'\n';
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