#include<bits/stdc++.h>
using namespace std;

int n,a[10005],f[1005],p[1005];

void mian(){
    cin>>n;
    memset(p,0x3f,sizeof(p));
    p[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        memset(f,0x3f,sizeof(f));
        for(int j=0;j<=1000;j++){
            if(j<=a[i])f[0]=min(f[0],p[j]+a[i]-j);
            else f[j-a[i]]=min(f[j-a[i]],p[j]);
            if(p[j]-j<=a[i])f[0]=min(f[0],j+a[i]);
            else{
                int c=min(j+a[i],p[j]-j-a[i]);
                if(c<=1000)f[c]=min(f[c],p[j]);
            }
        }
        swap(p,f);
    }
    cout<<*min_element(p,p+1001)<<'\n';
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