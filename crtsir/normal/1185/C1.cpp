#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,a[103];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt+=a[i];
		int tmp=cnt,ans=0;
		if(cnt>m){
			for(int j=i-1;j>=0&&tmp>m;j--)
			    tmp-=a[j],
				ans++;
		}
		cout<<ans<<' ';
		sort(a,a+i+1);
	}
}