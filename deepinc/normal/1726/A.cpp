#include<bits/stdc++.h>
using namespace std;
int n,m,a[233333];
int main(){
    int _; cin>>_; while(_--){
		scanf("%d",&n);
        int ans=-1e9; 
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        for(int i=2;i<=n;++i) ans=max(ans,a[i-1]-a[i]);
        for(int i=2;i<=n;++i) ans=max(ans,a[i]-a[1]);
        for(int i=1;i<n;++i) ans=max(ans,a[n]-a[i]);
        printf("%d\n",max(ans,a[n]-a[1]));
	}
}