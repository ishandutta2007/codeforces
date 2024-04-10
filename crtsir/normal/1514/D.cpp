#include<bits/stdc++.h>
using namespace std;
int n,T,a[300003];
vector<int>v[300003];
int query(int l,int r,int x){
	int ll=0,rr=v[x].size()-1,mid;
	while(ll!=rr){
		mid=(ll+rr)/2;
		if(v[x][mid]<l)
			ll=mid+1;
		else
			rr=mid;
	}
	int LL=0,RR=v[x].size()-1;
	while(LL!=RR){
		mid=(LL+RR+1)/2;
		if(v[x][mid]>r)
			RR=mid-1;
		else
			LL=mid;
	}
	return LL-ll+1;
}
int Query(int l,int r){
	int ret=0;
	for(int i=0;i<40;i++)
		ret=max(ret,query(l,r,a[(rand()*32768+rand())%(r-l+1)+l]));
	return ret;
}
int main(){
	srand(time(NULL)); 
	cin>>n>>T;
	for(int i=0;i<n;i++)v[i].push_back(-1);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);a[i]--;
		v[a[i]].push_back(i);}
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		l--;r--;
		printf("%d\n",max(1,Query(l,r)*2-(r-l+1)));
	}
}