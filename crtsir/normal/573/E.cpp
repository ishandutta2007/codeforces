#include<bits/stdc++.h>
using namespace std;
int B=512,invB=600;
const long long inf=22322123612123323333;
int n;
long long b[1000003],lzyb[1024],N,lb[1024],rb[1024],idx[1000003];
int k[1000003],allx[1024];
bool cmp(int x,int y){
	return k[x]<k[y];
}
double calc(int i,int j){
	if(k[i]==k[j])
		if(b[i]==b[j])return 1;
		else if(b[i]<b[j])return inf;
		else return -inf;
	else
		return (b[i]-b[j])*1.0/(k[i]-k[j]);
}
int v[1024][1024],tp[1024],j[1024];
bool del[1000003];
void rebuild(int T){
	for(int i=lb[T];i<=rb[T];i++)
		b[i]+=1ll*k[i]*allx[T]+lzyb[T];
	allx[T]=0;lzyb[T]=0;tp[T]=0;j[T]=0;
	for(int i=lb[T];i<=rb[T];i++)
		if(!del[idx[i]]){
			while(tp[T]>0&&k[idx[i]]==k[v[T][tp[T]-1]]&&b[v[T][tp[T]-1]]<=b[idx[i]]||tp[T]>1&&(b[v[T][tp[T]-2]]-b[v[T][tp[T]-1]])*(k[v[T][tp[T]-1]]-k[idx[i]])<(b[v[T][tp[T]-1]]-b[idx[i]])*(k[v[T][tp[T]-2]]-k[v[T][tp[T]-1]]))
				tp[T]--;
			if(tp[T]==0||k[v[T][tp[T]-1]]!=k[idx[i]])
				v[T][tp[T]++]=idx[i];
		}
}
inline pair<long long,int>query(int T){
	if(tp[T]==0)return {-inf,-1};
	while(j[T]<tp[T]-1&&b[v[T][j[T]]]+1ll*k[v[T][j[T]]]*allx[T]<=b[v[T][j[T]+1]]+1ll*k[v[T][j[T]+1]]*allx[T])
		j[T]++;
	return make_pair(b[v[T][j[T]]]+lzyb[T]+1ll*k[v[T][j[T]]]*allx[T],v[T][j[T]]);
}
int main(){
	cin>>n;
	if(n>300000)
		B=1024,invB=1024;
	for(int i=0;i<n;i++)
		scanf("%d",k+i),idx[i]=i,b[i]=k[i];
	N=(n-1)/B;
	for(int i=0;i<=N;i++){
		lb[i]=i*B;
		rb[i]=i*B+B-1;
		if(rb[i]>=n)rb[i]=n-1;
		sort(idx+lb[i],idx+rb[i]+1,cmp);
		rebuild(i);
	}
	long long ans=0,nw=0;
	for(int i=0;i<n;i++){
		pair<long long,int>ret={-inf,-1};
		for(int T=0;T<=N;T++)
			ret=max(ret,query(T));
		del[ret.second]=1;
		nw+=ret.first;
		ans=max(ans,nw);
		int blk=ret.second/B;
		for(int T=0;T<blk;T++)
			lzyb[T]+=k[ret.second];
		for(int T=N;T>blk;T--)
			allx[T]++;
		for(int t=lb[blk];t<ret.second;t++)
			b[t]+=k[ret.second];
		for(int t=rb[blk];t>ret.second;t--)
			b[t]+=k[t];
		rebuild(blk);
	}
	cout<<ans;
}