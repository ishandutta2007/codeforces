#include<bits/stdc++.h>
using namespace std;

int n,a[100005],b[100005];

void mian(){
    cin>>n;
    int g=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g=__gcd(g,a[i]);
    }
    int m=1;
    for(int i=1;i<=n;i++){
        a[i]/=g;
        if(abs(a[i])<abs(a[m]))m=i;
    }
    int sum=0;
    for(int i=1;i<=n;i++)if(i!=m){
        if((sum<0)^(a[m]<0)^(a[i]<0))sum+=a[i]*a[m],b[i]=a[m];
        else sum-=a[i]*a[m],b[i]=-a[m];
    }
    if(!sum)for(int i=1;i<=n;i++)if(i!=m){
        if(b[i]==a[m])sum+=a[i]*a[m],b[i]+=a[m];
        else sum-=a[i]*a[m],b[i]-=a[m];
        break;
    }
    for(int i=1;i<=n;i++)if(i!=m){
        cout<<b[i]<<' ';
    }else cout<<-sum/a[m]<<' ';
    cout<<'\n';
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