#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,k;
int a[200005],cnt[200005];
int gs(int l,int r){
	return cnt[r]-cnt[l-1];
} 
int main(){
	ios::sync_with_stdio(false); 
	cin>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
		for (int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
		int id1=0,id2=0,mn=1000000000;
		for (int i=1;i<=n;i++){
			if (2*gs(i,n)<k+n)continue;
			int l=i,r=n,pos=0;
			while(l<=r){
				int mid=(l+r)/2;
				if (2*gs(i,mid)>=k+n)pos=mid,r=mid-1;
				else l=mid+1;
			}
			if (pos-i<mn)mn=pos-i,id1=i,id2=pos;
		}
		cout<<id1<<' '<<id2<<endl;
		int tot=0;
		for (int i=1;i<=n;){
			int j=i,num=0;
			while(num<1){
				if (a[j]>=id1&&a[j]<=id2)num++;
				else num--;
				j++;
			}
			j--;
			tot++;
			if (tot==k)j=n;
			cout<<i<<' '<<j<<endl;
			i=j+1;
		}
		for (int i=1;i<=n;i++)cnt[i]=0;
	}
	return 0;
}