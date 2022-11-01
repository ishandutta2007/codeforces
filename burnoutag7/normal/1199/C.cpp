#include<bits/stdc++.h>
using namespace std;

int n,I,bts;
int a[400005];
map<int,int> mp;
int mpcnt;
int mx;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>I;
    bts=I*8/n;
    if(bts>=30){
        cout<<0<<endl;
        return 0;
    }
    bts=pow(2,bts);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]=0;
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
        it->second=++mpcnt;
    }
    for(int i=1;i<=n;i++){
        a[i]=mp[a[i]];
    }
    sort(a+1,a+1+n);
    int l=1,r=1;
    while(l<=n){
        while(a[r]<a[l]+bts&&r<=n)r++;
        r--;
        mx=max(mx,r-l+1);
        l++;
    }
    cout<<n-mx<<endl;

    return 0;
}