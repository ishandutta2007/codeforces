#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn];
int n,k;
void work(int l,int r){
	if (!k||l>=r-1)return;
	int mid = l+r>>1;
//	cout<<l<<" "<<mid<<" "<<r<<endl;
	swap(a[mid-1],a[mid]);
	k--;
	work(l,mid);work(mid,r);
}
int main(){
	scanf("%d%d",&n,&k);
	if ((k&1)==0){
		cout<<-1<<endl;
		return 0;
	}
	k/=2;
	for (int i=0;i<n;i++){
		a[i]=i+1;
	}
	work(0,n);
	if (k){
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}