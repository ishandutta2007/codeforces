#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[100005];
int b[100005];
int pos[100005];
int neg[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pos[i]=pos[i-1]|(a[i]>0);
            neg[i]=neg[i-1]|(a[i]<0);
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        bool fl=true;
        for(int i=n;i>=1;i--){
            if((b[i]>a[i]&&!pos[i-1])||(b[i]<a[i]&&!neg[i-1]))
                fl=false;
        }
        cout<<(fl?"YES":"NO")<<endl;
    }

    return 0;
}