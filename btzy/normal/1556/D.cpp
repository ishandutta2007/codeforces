#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=10000;
int arr[MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    --k;
    int o01,o12,o20;
    int a01,a12,a20;
    cout<<"or 1 2"<<endl;
    cin>>o01;
    if(o01==-1)return 0;
    cout<<"or 2 3"<<endl;
    cin>>o12;
    if(o12==-1)return 0;
    cout<<"or 1 3"<<endl;
    cin>>o20;
    if(o20==-1)return 0;
    cout<<"and 1 2"<<endl;
    cin>>a01;
    if(a01==-1)return 0;
    cout<<"and 2 3"<<endl;
    cin>>a12;
    if(a12==-1)return 0;
    cout<<"and 1 3"<<endl;
    cin>>a20;
    if(a20==-1)return 0;
    arr[0]=(o01&o12&o20&(a01|a20))|(o01&o20&~o12);
    arr[1]=(o01&o12&o20&(a12|a01))|(o12&o01&~o20);
    arr[2]=(o01&o12&o20&(a20|a12))|(o20&o12&~o01);
    for(int i=3;i<n;++i){
        int oo,aa;
        cout<<"or 1 "<<(i+1)<<endl;
        cin>>oo;
        if(oo==-1)return 0;
        cout<<"and 1 "<<(i+1)<<endl;
        cin>>aa;
        if(aa==-1)return 0;
        arr[i]=arr[0]^oo^aa;
    }
    sort(arr,arr+n);
    cout<<"finish "<<arr[k]<<endl;
}