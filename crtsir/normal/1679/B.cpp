#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[200003],nw;
int main(){
	int n,q;
	cin>>n>>q;
	long long sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].second);
		sum+=a[i].second;
	}
	for(int i=1;i<=q;i++){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if(tp==2){
			sum=1ll*x*n;
			nw=make_pair(i,x);
		}else{
			scanf("%d",&y);x--;
			sum=sum-max(nw,a[x]).second;
			a[x]={i,y};
			sum=sum+max(nw,a[x]).second;
		}
		cout<<sum<<endl;
	}
}