#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int w,n;
struct st{
	int data;
	int index;
}a[MAXN];
bool cmp(st st1,st st2){
	return st1.data>st2.data;
}
int ans[MAXN];
int main(){
	cin>>n>>w;
	memset (ans,0,sizeof(ans));
	for (int i=0;i<n;i++){
		cin>>a[i].data;
		a[i].index=i;
		int temp = (a[i].data+1)/2;
		ans[i]=temp;
		w-=temp;
		if (w<0){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	sort(a+0,a+n,cmp);
	for (int i=0;i<n;i++){
		if (w>=a[i].data-ans[a[i].index]){
			w-=a[i].data-ans[a[i].index];
			ans[a[i].index]=a[i].data;
		}else if (w!=0){
			ans[a[i].index]+=w;
			w=0;
		}
		if (w==0){
			break;
		}
	}
	for (int i=0;i<n;i++){
		cout<<ans[i];
		if (i!=n-1){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
	return 0;
}