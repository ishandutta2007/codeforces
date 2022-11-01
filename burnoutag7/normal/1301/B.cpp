#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int mx=0,mn=1e9;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            if(a[i]!=-1&&((i>0&&a[i-1]==-1)||(i+1<n&&a[i+1]==-1))){
                mx=max(mx,a[i]);
                mn=min(mn,a[i]);
            }
        }
        if(mn>mx){
            cout<<"0 0"<<endl;
            continue;
        }
        int k=(mn+mx)>>1;
        for(int i=0;i<n;i++){
            if(a[i]==-1)a[i]=k;
        }
        int m=0;
        for(int i=1;i<n;i++){
            m=max(m,abs(a[i]-a[i-1]));
        }
        cout<<m<<' '<<k<<endl;
    }

    return 0;
}