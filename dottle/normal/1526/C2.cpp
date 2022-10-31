#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

priority_queue<int,vector<int>,greater<int> >q;

int a[N],n,ans;

main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1,s=0;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0)ans++,s+=a[i];
		else {
			if(s+a[i]>=0)ans++,s+=a[i],q.push(a[i]);
			else {
				if(!q.empty()&&q.top()<a[i])
					s+=a[i]-q.top(),q.pop(),q.push(a[i]);
			}
		}
	} 
	cout<<ans;
}