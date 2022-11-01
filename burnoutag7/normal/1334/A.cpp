#include<bits/stdc++.h>
using namespace std;

int T,n;
int p[105],c[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        bool f=true;
        for(int i=1;i<=n;i++){
            cin>>p[i]>>c[i];
            if(p[i]<p[i-1]||c[i]<c[i-1]||c[i]-c[i-1]>p[i]-p[i-1])f=false;
        }
        cout<<(f?"YES":"NO")<<endl;
    }

    return 0;
}