#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n;
ll sum,Xor;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;sum=Xor=0;
        for(int i=1;i<=n;i++){
            int a;cin>>a;
            sum+=a;Xor^=a;
        }
        if(sum==0){
            cout<<3<<endl;
            cout<<"2 1 1"<<endl;
            continue;
        }
        if(sum==1){
            cout<<1<<endl;
            cout<<3<<endl;
            continue;
        }
        cout<<3<<endl;
        for(int j=60;;j--){
            if(sum&(1ll<<j)){
                bool p=sum&1;
                cout<<((1ll<<(j+1))+p)<<' ';
                sum+=((1ll<<(j+1))+p);
                Xor^=((1ll<<(j+1))+p);
                cout<<(((Xor<<1)-sum)>>1)<<' '<<(((Xor<<1)-sum)>>1)<<endl;
                break;
            }
        }
    }

    return 0;
}