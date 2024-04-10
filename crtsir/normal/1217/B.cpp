#include<bits/stdc++.h>
using namespace std;
long long t,n,a[103],b[103],f;
bool ok;
pair<long long,long long>c[103];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>f; 
		long long maxn=0,ans=0;
		for(long long i=0;i<n;i++)cin>>a[i]>>b[i],c[i].first=b[i]-a[i],c[i].second=i,maxn=max(maxn,a[i]);
		sort(c,c+n);
		if(c[0].first>=0&&maxn<f){
			cout<<-1<<endl;
			continue; 
		}
		f-=maxn;
		if(f>0)ans=(f-1)/(-c[0].first)+1;
		cout<<ans+1<<endl; 
	}
}