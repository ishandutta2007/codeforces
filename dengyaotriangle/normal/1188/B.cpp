#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int n;
long long p,k;
long long a[maxn];
map<int,int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>p>>k;
    for(int i=1;i<=n;i++){
        long long t;
        cin>>t;
        long long p2=(t*t)%p,p4=(p2*p2)%p;
        a[i]=(p4-(k*t)%p+p)%p;
        mp[a[i]]++;
    }
    long long ans=0;
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
        long long cur=(*it).second;
        ans+=(cur*(cur-1))/2;
    }
    cout<<ans;
    return 0;
}