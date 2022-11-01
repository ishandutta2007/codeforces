#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define R register int
#define I inline
#define N 200001
vector<int>G[N];
int lpos[N],rpos[N],a[N],tag[600000];
I void PutDown(int p){
	if(tag[p]!=-1){
		tag[p<<1]=tag[p<<1|1]=tag[p];
		tag[p]=-1;
	}
}
I void Cover(int p,int lf,int rt,const int l,const int r,const int d){
	if(l<=lf&&rt<=r){
		tag[p]=d;
	}else{
		PutDown(p);
		int mid=lf+rt>>1;
		if(l<=mid){
			Cover(p<<1,lf,mid,l,r,d);
		}
		if(r>mid){
			Cover(p<<1|1,mid+1,rt,l,r,d);
		}
	}
	//printf("T%d %d %d\n",lf,rt,tag[p]);
}
I int GetColor(int p,int lf,int rt,const int x){
	if(tag[p]!=-1){
		return tag[p];
	}
	int mid=lf+rt>>1;
	if(x>mid){
		return GetColor(p<<1|1,mid+1,rt,x);
	}
	return GetColor(p<<1,lf,mid,x);
}
int main(){
	int n,ans=0;
	cin>>n;
	for(R i=1;i<=n;i++){
		cin>>a[i];
		if(lpos[a[i]]==0){
			lpos[a[i]]=i;
		}
		rpos[a[i]]=i;
	}
	for(R i=1;i<=n;i++){
		if(lpos[i]<rpos[i]-1){
			G[lpos[i]].push_back(rpos[i]);
		}
	}
	int rt=0;
	priority_queue<pair<int,int>>Q;
	for(int i=1;i<=n;i++){
		for(int T:G[i]){
			//printf("L%d %d\n",i,T);
			Q.push(make_pair(T,i));
		}
		while(Q.empty()==false&&Q.top().first-2<rt){
			Q.pop();
		}
		if(Q.empty()==false&&rt<i){
			//printf("Q%d %d %d\n",rt,Q.top().first,Q.top().second);
			Cover(1,1,n,Q.top().second,Q.top().first-1,1);
			Cover(1,1,n,Q.top().second,Q.top().second,0);
			rt=Q.top().first-1;
			Q.pop();
		}
	}
	for(R i=2;i!=n;i++){
		ans+=GetColor(1,1,n,i); 
	}
	cout<<ans;
	return 0;
}