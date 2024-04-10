#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

void mian(){
    int n,sum=0,mn=1e9,mnp=-1;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]&1){
            if(a[i]<mn){
                mn=a[i];
                mnp=i;
            }
        }
    }
    if(mnp==-1||!isprime(sum)){
        cout<<n<<'\n';
        for(int i=1;i<=n;i++)cout<<i<<' ';
        cout<<'\n';
    }else{
        cout<<n-1<<'\n';
        for(int i=1;i<=n;i++)if(i!=mnp+1)cout<<i<<' ';
        cout<<'\n';
    }
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