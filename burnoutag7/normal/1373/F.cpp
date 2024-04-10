#include<bits/stdc++.h>
using namespace std;

int n,a[1000005],b[1000005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        a[n+1]=a[1];
        int l=0,r=b[1],m,f=0;
        while(l<=r){
            m=l+r>>1;
            int c=min(b[1]-m,a[2]);
            for(int i=2;i<=n;i++){
                if(b[i]+c<a[i]){
                    c=-1;
                    break;
                }
                c=min(b[i]+c-a[i],a[i+1]);
            }
            if(c==-1){
                r=m-1;
            }else if(c+m>=a[1]){
                f=1;
                break;
            }else l=m+1;
        }
        cout<<(f?"YES":"NO")<<'\n';
    }

    return 0;
}