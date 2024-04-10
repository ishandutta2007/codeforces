#include<bits/stdc++.h>
using namespace std;

int n,p;
int a[100005];
map<int,int> mp;

inline int f(const int &x){
    int v=upper_bound(a+1,a+1+n,x-1)-a-1;
    for(int i=x;i<x+n;i++){
        v+=mp[i];
        if(v==p)return 0;
        v--;
    }
    return 1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a+1,a+1+n);
    int s=0;
    {
        int cur=0;
        for(int i=1;i<=n;i++){
            s=max(s,a[i]-cur);
            cur++;
        }
    }
    int t=s-1;
    {
        int l=s,r=s+1e5,m;
        while(l<=r){
            m=l+r>>1;
            if(f(m)){
                l=m+1;
                t=m;
            }else{
                r=m-1;
            }
        }
    }
    cout<<t-s+1<<endl;
    for(int i=s;i<=t;i++)cout<<i<<' ';
    cout<<endl;

    return 0;
}