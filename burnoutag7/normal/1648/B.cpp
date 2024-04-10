#include<bits/stdc++.h>
using namespace std;

int n,c,a[1000005],b[1000005],p[1000005];

void mian(){
    cin>>n>>c;
    memset(b+1,0,c*4);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=c;i++)p[i]=p[i-1]+b[i];
    if(!b[1]){
        cout<<"No\n";
        return;
    }
    for(int i=2;i<=c;i++)if(b[i]){
        for(int j=i+i;j<=c;j+=i){
            int k=min(j+i-1,c);
            if(p[k]-p[j-1]&&!b[j/i]){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
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