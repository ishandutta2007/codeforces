#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;

int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    long long ans=0;
    for(int i=1;i<=n+1;i++){
        long long fa=a[i],fb=a[i-1];
        if(fa>fb)swap(fa,fb);
        long long c1=fa*(fb-fa);
        long long c2=(n-fb+1)*(fb-fa);
        ans+=c1+c2;
    }
    cout<<ans/2;
    return 0;
}