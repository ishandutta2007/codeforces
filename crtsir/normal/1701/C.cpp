#include<bits/stdc++.h>
using namespace std;
int T,n,m,a,cnt[200003];
bool check(int x){
	long long ret=0;
	for(int i=0;i<n;i++)
		ret=ret+min(x,cnt[i])+(x-min(x,cnt[i]))/2;
	return ret>=m;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)cnt[i]=0;
		for(int i=0;i<m;i++)
			scanf("%d",&a),cnt[a-1]++;
		int l=0,r=2*m,mid;
		while(l!=r){
			mid=(l+r)/2;
			if(check(mid))
				r=mid;
			else
				l=mid+1;
		}
		cout<<l<<endl;
	}
}