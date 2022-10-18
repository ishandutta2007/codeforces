#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n,k;
long long x[maxn];
int main(){
    cin>>n>>k;
    long long st=((long long)(1+k)*k)/2ll;
    if(st>n){
        cout<<"NO";
        return 0;
    }
    long long dv=n-st;
    long long wa=dv/k;
    dv%=k;
    for(int i=1;i<=k;i++) x[i]=i+wa;
    if(wa==0&&k<4){
        long long t1=0,cur=1;
        for(int i=0;i<k;i++){
            t1+=cur;
            cur*=2;
        }
        if(n>t1){
            cout<<"NO";
            return 0;
        }
        cout<<"YES\n";
        x[1]=1;
        x[2]=2;
        x[3]=n-3;
        for(int i=1;i<=k;i++)cout<<x[i]<<' ';
        return 0;
    }
    if(dv==k-1&&dv!=0){
        dv--;
        x[k]++;
    }
    for(int i=k;i>=k-dv+1;i--){
        x[i]++;
    }
    cout<<"YES\n";
    for(int i=1;i<=k;i++){
        cout<<x[i]<<' ';
    }
    return 0;
}