#include<bits/stdc++.h>
using namespace std;
int n;
 
int ask(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	int x;cin>>x;return x;
}
void get(int x){
	cout<<"! "<<x<<endl;
	exit(0);
}
signed main(){
	scanf("%d",&n);
	int p=ask(1,n);
	if(p!=1&&ask(1,p)==p){
		if(p==2)get(1);
		// [1,p)
		int l=1,r=p-1,ans;
		while(l<=r){
			int mid=l+r>>1;
			if(ask(mid,p)==p)l=mid+1,ans=mid;
			else r=mid-1;
		} 
		get(ans);
	}else{ 
		if(p==n-1)get(n);
		// (p,n] 
		int l=p+1,r=n,ans;
		while(l<=r){
			int mid=l+r>>1;
			if(ask(p,mid)==p)r=mid-1,ans=mid;
			else l=mid+1;
		}
		get(ans);
	}
	//cout<<"asdkhaskdhk"
}