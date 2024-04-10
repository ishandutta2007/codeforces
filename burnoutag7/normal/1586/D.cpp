#include<bits/stdc++.h>
using namespace std;

int n,d[105],p[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        cout<<"? ";
        for(int j=1;j<n;j++){
            cout<<i+1<<' ';
        }
        cout<<1<<endl;
        int k;
        cin>>k;
        d[k]=-i;
    }
    for(int i=1;i<n;i++){
        cout<<"? ";
        for(int j=1;j<n;j++){
            cout<<1<<' ';
        }
        cout<<i+1<<endl;
        int k;
        cin>>k;
        d[k]=i;
    }
    int mn=*min_element(d+1,d+n+1);
    p[n]=mn<0?-mn+1:1;
    cout<<"! ";
    for(int i=1;i<n;i++){
        p[i]=p[n]+d[i];
        cout<<p[i]<<' ';
    }
    cout<<p[n]<<endl;

    return 0;
}