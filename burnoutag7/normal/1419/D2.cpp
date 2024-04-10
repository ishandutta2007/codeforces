#include<bits/stdc++.h>
using namespace std;

int n,a[100005],b[100005],ansv[100005];

bool check(int x){
    memset(b,0,sizeof(b));
    for(int i=1;i<=x;i++){
        b[i<<1]=a[i];
    }
    multiset<int> s;
    for(int i=x+1;i<=n;i++){
        s.insert(a[i]);
    }
    for(int i=1;i<=n;i+=2){
        if(s.upper_bound(max(b[i-1],b[i+1]))==s.end())return false;
        b[i]=*s.upper_bound(max(b[i-1],b[i+1]));
        s.erase(s.find(b[i]));
    }
    for(int i=1;i<=n;i++)if(!b[i]){
        b[i]=*s.begin();
        s.erase(s.begin());
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=0,r=n-1>>1,m,ans;
    while(l<=r){
        m=l+r>>1;
        if(check(m)){
            ans=m;
            memcpy(ansv,b,sizeof(ansv));
            l=m+1;
        }else{
            r=m-1;
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)cout<<ansv[i]<<' ';
    cout<<endl;

    return 0;
}