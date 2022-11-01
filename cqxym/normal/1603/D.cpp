#include<iostream>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 100001
#define INF 999999999999
int phi[N],prime[9592];
bool vis[N];
L sum[N];
I void GetPhi(){
	phi[1]=1;
	int t=0;
	for(R i=2;i!=N;i++){
		if(vis[i]==false){
			phi[i]=i-1;
			prime[t]=i;
			t++;
		}
		for(R j=0;i*prime[j]<N;j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	for(R i=1;i!=N;i++){
		sum[i]=sum[i-1]+phi[i];
	}
}
I L GetC(int l,int r){
	if(l>r){
		return INF;
	}
	L res=0;
	int t,q;
	for(R i=l;i<=r;i=q+1){
		t=r/i;
		q=r/t;
		int x=0;
		if(i>=l){
			x=q-i+1;
		}else if(q>=l){
			x=q-l+1;
		}
		res+=sum[t]*x;
	}
	return res;
}
L f[N][17];
I void Solve(int l,int r,int cl,int cr,const int k){
	if(l<=r){
		int mid=l+r>>1,pos,tem;
		f[mid][k]=INF;
		pos=cl;
		tem=min(mid,cr);
		L c=GetC(tem+1,mid);
		for(R i=tem;i>=cl;i--){
			L cur=f[i][k-1]+c;
			if(cur<=f[mid][k]){
				f[mid][k]=cur;
				pos=i;
			}
			if(i<=mid){
				if(c==INF){
					c=sum[mid/i];
				}else{
					c+=sum[mid/i];
				}
			}
		}
		Solve(l,mid-1,cl,pos,k);
		Solve(mid+1,r,pos,cr,k);
	}
}
int main(){
	GetPhi();
	for(R i=1;i!=N;i++){
		f[i][0]=INF;
	}
	for(R i=1;i!=N;i++){
		f[i][1]=(1ll+i)*i>>1;
	}
	for(R i=2;i!=17;i++){
		Solve(1,N-1,1,N-1,i);
	}
	int t,n,k;
	cin>>t;
	for(R i=0;i!=t;i++){
		cin>>n>>k;
		if(k>17||1<<k>n){
			cout<<n<<endl;
		}else{
			cout<<f[n][k]<<endl;
		}
	}
	return 0;
}