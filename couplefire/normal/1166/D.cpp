#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    int q;
    cin>>q;
    while(q--){
        long long a,b,m;
        cin>>a>>b>>m;
        long long q=1;
        long long k=2;
        if(a==b){
            cout<<1<<" "<<a<<endl;
            continue;
        }
        while(q*(a+m)<b){
            k++;
            q*=2;
        }
        if(q*(a+1)>b){
            cout<<-1<<endl;
            continue;
        }
        cout<<k<<" "<<a<<" ";
        for(int i=2;i<k;i++){
            cout<<(((b>>(k-i-1))+1)>>1)<<" ";
        }
        cout<<b<<endl;
    }
}