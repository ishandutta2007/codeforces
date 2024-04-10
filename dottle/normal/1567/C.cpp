#include<bits/stdc++.h>
#define int long long
const int N=20;
using namespace std;

int t,n,a[N],k,x,ans;

main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n,x=n,ans=0,k=0;
		while(x)a[k]=x%10,x/=10,k++;
		for(int i=0;i<1<<max(0ll,k-2);i++){
			int na=1;
			for(int j=0;j<k;j++){
				int nw=a[j];
				if(j>=2&&(i>>(j-2)&1))nw--;
				if(i>>j&1)nw+=10;
				na*=nw>=10?19-nw:nw+1;
			}
			ans+=na; 
		}
		cout<<ans-2<<endl;
	}
}