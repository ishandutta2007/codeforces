#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T,n,x;
int a[100005];
ll suf;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>x;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        int tot=n;
        suf=0;
        for(int i=n;i>=1;i--){
            suf+=a[i];
            if(suf<(ll)(n-i+1)*x){
                tot=n-i;
                break;
            }
        }
        cout<<tot<<endl;
    }

    return 0;
}