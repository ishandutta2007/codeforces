#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[200005];
ll pre[200005],mn[2];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ll odd=0,even=0;
        mn[0]=mn[1]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            odd+=a[i]*(i&1);
            pre[i]=pre[i-1]+(i&1^1)*a[i]-(i&1)*a[i];
            even=max(even,pre[i]-mn[i&1]);
            mn[i&1]=min(mn[i&1],pre[i]);
        }
        cout<<odd+even<<endl;
    }

    return 0;
}