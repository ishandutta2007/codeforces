#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        if(n<4){
            cout<<"-1\n";
            continue;
        }
        for(int i=1;i<=n;i+=5){
            a[i]=i+2;
            a[i+1]=i;
            a[i+2]=i+3;
            a[i+3]=i+1;
            a[i+4]=i+4;
        }
        if(n%5==0){
            //do nothing
        }else
        if(n%5==1){
            a[n]=n;
            swap(a[n],a[n-2]);
            swap(a[n-1],a[n]);
        }else
        if(n%5==2){
            a[n]=n;
            a[n-1]=n-1;
            swap(a[n-1],a[n-3]);
            swap(a[n-2],a[n-1]);
        }else
        if(n%5==3){
            a[n]=n-1;
            swap(a[n-3],a[n-1]);
        }else
        if(n%5==4){
            //do nothing
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}