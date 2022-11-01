#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[100005];
ll f[100005][450],pre[100005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        memset(f[i],0,sizeof(f[i]));
    }
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
        f[i][1]=max(f[i-1][1],(ll)a[i]);
        for(int j=2;j*(j+1)/2<=i;j++){
            f[i][j]=f[i-1][j];
            if(f[i-j][j-1]>pre[i]-pre[i-j])f[i][j]=max(f[i][j],pre[i]-pre[i-j]);
        }
    }
    cout<<min_element(f[n]+1,f[n]+450)-f[n]-1<<'\n';
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