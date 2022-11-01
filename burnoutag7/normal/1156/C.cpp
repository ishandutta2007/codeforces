#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[200005];
int l,r,m;
int ans;

bool chk(int x){
	if(x>n/2)return 0;
	for(int i=x;i>=1;i--){
        if(a[n-x+i]-a[i]<k)return 0;
    }
	return 1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    l=1,r=n;
    while(l<=r){
        m=(l+r+1)/2;//cout<<m<<endl;
        if(chk(m)){
            l=m+1;
            ans=m;
        }else{
            r=m-1;
        }
    }
    cout<<ans<<endl;

    return 0;
}