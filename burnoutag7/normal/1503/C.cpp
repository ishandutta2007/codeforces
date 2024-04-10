#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
pair<int,int> a[100005];
ll ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        ans+=a[i].second;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int j=i,mx=a[i].first+a[i].second;
        while(j<n&&a[j+1].first<=mx){
            j++;
            mx=max(mx,a[j].first+a[j].second);
        }
        i=j;
        if(i<n)ans+=a[i+1].first-mx;
    }
    cout<<ans;

    return 0;
}