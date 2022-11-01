#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
bool b[200005];

void mian(){
    memset(b+1,0,n);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%2){
        cout<<"-1\n";
        return;
    }
    int par=n;
    for(int i=2;i<=n;i++){
        if(sum<0&&a[i]<0){
            b[i-1]=1;
            par--;
            sum+=2;
            i++;
        }else if(sum>0&&a[i]>0){
            b[i-1]=1;
            par--;
            sum-=2;
            i++;
        }
    }
    cout<<par<<'\n';
    for(int i=1;i<=n;i++){
        cout<<i<<' '<<(i+b[i])<<'\n';
        if(b[i])i++;
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