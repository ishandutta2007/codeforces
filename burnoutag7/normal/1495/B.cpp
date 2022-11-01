//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

int n,a[100005],ld[100005],rd[100005],lu[100005],ru[100005],pu[100005],su[100005];

bool left(int x){
    if(pu[x-ld[x]]>=max(ld[x],rd[x]))return false;
    return ld[x]-(ld[x]&1^1)<rd[x];
}

bool right(int x){
    if(su[x+rd[x]]>=max(ld[x],rd[x]))return false;
    return rd[x]-(rd[x]&1^1)<ld[x];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=a[1];
    a[n+1]=a[n];
    for(int i=1;i<=n;i++){
        if(a[i-1]<a[i])ld[i]=ld[i-1]+1;
        else ld[i]=0;
        if(a[i-1]>a[i])lu[i]=lu[i-1]+1;
        else lu[i]=0;
        pu[i]=max(pu[i-1],max(ld[i],lu[i]));
    }
    for(int i=n;i>=1;i--){
        if(a[i+1]<a[i])rd[i]=rd[i+1]+1;
        else rd[i]=0;
        if(a[i+1]>a[i])ru[i]=ru[i+1]+1;
        else ru[i]=0;
        su[i]=max(su[i+1],max(rd[i],ru[i]));
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=left(i)&&right(i);
    }
    cout<<ans<<endl;

    return 0;
}