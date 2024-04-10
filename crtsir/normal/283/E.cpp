#include<bits/stdc++.h>
using namespace std;
struct segmentree{
	int dat[2][262144];
	bool lzy[262144];
	void init(){
		memset(dat,0,sizeof(dat));
		memset(lzy,0,sizeof(lzy));
	}
	int query(int tp,int l,int r,int L,int R,int k){
		if(L<=l&&r<=R)return dat[tp][k];
		if(l>R||r<L)return 0;
		return query(tp^lzy[k],l,l+r>>1,L,R,k<<1)+query(tp^lzy[k],l+r+1>>1,r,L,R,k<<1|1);
	}
	void reverse(int l,int r,int L,int R,int k){
		if(L<=l&&r<=R){lzy[k]^=1;swap(dat[0][k],dat[1][k]);return;}
		if(l>R||r<L)return;
		reverse(l,l+r>>1,L,R,k<<1);
		reverse(l+r+1>>1,r,L,R,k<<1|1);
		dat[0][k]=dat[0][k<<1]+dat[0][k<<1|1];
		dat[1][k]=dat[1][k<<1]+dat[1][k<<1|1];
		if(lzy[k])swap(dat[0][k],dat[1][k]);
	}
}tr;
int n,q,s[100003];
vector<int>vr[100003],vl[100003];
long long ans=0;
int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++)
		scanf("%d",s+i);
	sort(s,s+n);
	ans=1ll*n*(n-1)*(n-2)/6; 
	for(int i=0;i<q;i++){
		int a,b,l,r,rl,rr;
		scanf("%d%d",&a,&b);
		l=0;r=n-1;
		while(l!=r){
			int mid=(l+r>>1);
			if(s[mid]>=a)
				r=mid;
			else
				l=mid+1;
		}rl=l;
		l=0;r=n-1;
		while(l!=r){
			int mid=(l+r+1>>1);
			if(s[mid]<=b)
				l=mid;
			else
				r=mid-1;
		}
		rr=r;
		vr[rl].push_back(rr);
		vl[rr+1].push_back(rl);
	}tr.init();
	for(int i=0;i<n;i++)
		tr.dat[0][i+131072]=1;
	for(int i=131071;i>0;i--)
		tr.dat[0][i]=tr.dat[0][i*2]+tr.dat[0][i*2+1];
	for(int i=0;i<n;i++){ 
		tr.reverse(0,131071,i,i,1);
		for(int j=0;j<vl[i].size();j++)
			tr.reverse(0,131071,vl[i][j],i-1,1);
		for(int j=0;j<vr[i].size();j++)
			tr.reverse(0,131071,i,vr[i][j],1);
		int xx=tr.query(1,0,131071,0,n-1,1)-tr.query(1,0,131071,i,i,1);
		ans=ans-1ll*xx*(xx-1)/2;
	}cout<<ans;
}