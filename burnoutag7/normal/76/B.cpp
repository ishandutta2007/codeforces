#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005],b[100005],ans;
bool use[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    {
        static int buf;
        cin>>buf>>buf;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    a[0]=b[0]=-1e9;
    a[n+1]=b[m+1]=1e9;
    for(int i=1,l=0,r=0;i<=n;i++){
        while(b[l+1]<=a[i])l++;
        while(b[r]<a[i])r++;
        if(l>=1&&a[i]-b[l]<b[r]-a[i]){
            if(b[l]-a[i-1]!=a[i]-b[l])ans+=use[l];
            use[l]=1;
            continue;
        }
        if(r<=m&&a[i]-b[l]>b[r]-a[i]){
            ans+=use[r];
            use[r]=1;
            continue;
        }
        if(l>=1&&(!use[l]||b[l]-a[i-1]==a[i]-b[l])){
            use[l]=1;
        }else{
            ans+=use[r];
            use[r]=1;
        }
    }
    cout<<ans<<endl;

    return 0;
}