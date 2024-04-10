#include<bits/stdc++.h>
using namespace std;
 
int q;
int n,k,cnt;
int a[200005];
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin>>q;
    while(q--){
        cin>>n>>k;
        cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt+=a[i]%2;
        }
        if(cnt<k||(cnt-k)%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        int tmp=0;
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            if(a[i]%2){
                tmp++;
                if(tmp<k)cout<<i<<' ';
                else{
                    cout<<n<<' ';
                    break;
                }
            }
        }
        cout<<endl;
    }
 
    return 0;
}