#include<bits/stdc++.h>
using namespace std;

int n;
int a[105];
int sum;
int k,sk;
int r[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sk=a[1];
    k=1;
    r[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]*2<=a[1]){
            r[++k]=i;
            sk+=a[i];
        }
    }
    if(sk*2>sum){
        cout<<k<<endl;
        for(int i=1;i<=k;i++){
            cout<<r[i]<<' ';
        }
        cout<<endl;
    }else{
        cout<<0<<endl;
    }

    return 0;
}