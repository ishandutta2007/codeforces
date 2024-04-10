#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,t,k=-1;
int qry(int a,int b){
	a=max(a,1);
	b=min(b,n);
	cout<<'?'<<' '<<a<<' '<<b<<endl;
	cout.flush();
	int x;cin>>x;
	return b-a+1-x;
}
void upd(int b){
	cout<<'!'<<' '<<b<<endl;
	cout.flush();
}
const int SZ=16;
int blk=-1;
int tot[N];
#define lowbit(x) (x&(-x))
void add(int x,int val){
	for(;x<=n;x+=lowbit(x))
		tot[x]+=val;
}
int Qry(int x){
	int res=0;
	for(;x;x-=lowbit(x))
		res+=tot[x];
	return res;
}
int Tot(int x){
	return Qry(x);
}
signed main(){
	cin>>n>>t;
	for(int SJYAKIOI=1;SJYAKIOI<=t;SJYAKIOI++){
		cin>>k;
		if(blk==-1){
			int lst=0;
			for(int i=1;i<=n;i+=SZ)
				add(i/SZ+1,qry(i,i+SZ-1));
			blk=0;
		}
		//
		int id;
		{
			int l=1,r=n/SZ+1;
			while(l<=r){
				int mid=l+r>>1;
				if(k<=Tot(mid)){
					id=mid;
					r=mid-1;
				}else l=mid+1;
			}
		}
		{
			int st=(id-1)*SZ+1;
			int l=1,r=SZ,ans=-1;
			while(l<r){
				int mid=l+r>>1;
				if(qry(1,st+mid-1)>=k){
					r=mid;
				}else l=mid+1;
			}
			ans=st+r-1;
			upd(ans);
			add((ans-1)/SZ+1,-1);
		}
	}
}