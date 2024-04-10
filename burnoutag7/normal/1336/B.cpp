#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int nr,ng,nb;
int r[100005];
int g[100005];
int b[100005];

inline ll dist(int a,int b,int c){
    return (ll)(a-b)*(a-b)+(ll)(a-c)*(a-c)+(ll)(b-c)*(b-c);
}

inline ll calc(int i,int j,int *ar,int sz){
    int mid=(i+j+1)>>1;
    int k=lower_bound(ar+1,ar+1+sz,mid)-ar;
    if(k<1)k++;
    if(k>sz||(k>1&&ar[k]-mid>mid-ar[k-1]))k--;
    return dist(i,j,ar[k]);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>nr>>ng>>nb;
        for(int i=1;i<=nr;i++)cin>>r[i];
        for(int i=1;i<=ng;i++)cin>>g[i];
        sort(g+1,g+1+ng);
        ng=unique(g+1,g+1+ng)-g-1;
        for(int i=1;i<=nb;i++)cin>>b[i];
        sort(b+1,b+1+nb);
        nb=unique(b+1,b+1+nb)-b-1;
        ll ans=8e18;
        for(int i=1;i<=nr;i++){
            int j=upper_bound(g+1,g+1+ng,r[i])-g-1;
            if(j&&j<=ng)ans=min(ans,calc(r[i],g[j],b,nb));
            j=lower_bound(g+1,g+1+ng,r[i])-g;
            if(j&&j<=ng)ans=min(ans,calc(r[i],g[j],b,nb));

            j=upper_bound(b+1,b+1+nb,r[i])-b-1;
            if(j&&j<=nb)ans=min(ans,calc(r[i],b[j],g,ng));
            j=lower_bound(b+1,b+1+nb,r[i])-b;
            if(j&&j<=nb)ans=min(ans,calc(r[i],b[j],g,ng));
        }
        cout<<ans<<'\n';
    }

    return 0;
}