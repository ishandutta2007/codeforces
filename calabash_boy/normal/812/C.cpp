#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
struct aaa{
	int value,index;
}cost[MAXN];
int m,n,k,s,mid,l,r,costt;
int kk;
bool cmp(aaa a1,aaa a2){
	return a1.value+kk*a1.index<a2.value+kk*a2.index;
}
bool can(long long x){
	kk=x;
	sort(cost+0,cost+n,cmp);
	costt=0;
	for (int i=0;i<x;i++){
		costt+=cost[i].value+kk*(cost[i].index+1);
		if (costt>s){
			return false;
		}
	}
	return true;
}
int main(){
	cin>>n>>s;
	for (int i=0;i<n;i++){
		scanf("%I64d",&cost[i].value);
		cost[i].index=i;
	}
	l=0;
	r=n;
	while (r-l>1){
		mid=(l+r)>>1;
		if (can(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	if (can(r)){
		cout<<r<<" "<<costt<<endl;
		return 0;
	}
	if (can(l)){
		cout<<l<<" "<<costt<<endl;
	}
}