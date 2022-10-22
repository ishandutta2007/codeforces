#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const ll mod=998244353ll;
int n,m,k;
ll a[N];
ll mn=inf,mx;
int nxt[N];
int st[N][20];
int sta[N][20];
int lg[N];
int query(int x,int y){
	return min(st[x][lg[y-x+1]],st[y-(1<<lg[y-x+1])+1][lg[y-x+1]]);
}
int querya(int x,int y){
	return min(sta[x][lg[y-x+1]],sta[y-(1<<lg[y-x+1])+1][lg[y-x+1]]);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];a[i+n]=a[i+2*n]=a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if(mx<=mn*2){
		for(i=1;i<=n;i++) cout<<-1<<" ";
		return 0;
	}
	lg[1]=0;
	for(i=1;i<=3*n;i++){
		lg[i]=lg[i-1];
		if((1<<lg[i]+1)<=i) lg[i]++;
	}
	for(i=1;i<=3*n;i++) sta[i][0]=a[i];
	for(j=1;j<20;j++){
		for(i=1;i+(1<<j)-1<=3*n;i++)
			sta[i][j]=min(sta[i][j-1],sta[i+(1<<j-1)][j-1]);
	}
	for(i=n*3;i;i--){
		int l=i+1,r=3*n;
		while(r>l){
			int mid=(l+r)>>1;
			if(querya(i,mid)<(a[i]+1)/2) r=mid;
			else l=mid+1; 
		}
		nxt[i]=l;
	}
	for(i=1;i<=3*n;i++) st[i][0]=nxt[i];
	for(j=1;j<20;j++){
		for(i=1;i+(1<<j)-1<=3*n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	}
	
	for(i=1;i<=n;i++){
		int l=i+1,r=3*n;
		//cout<<i<<endl;
		while(r>l){
			int mid=(l+r)>>1;
			//cout<<query(i,mid-1)<<" "<<mid<<endl;
			if(query(i,mid-1)<=mid) r=mid;
			else l=mid+1; 
		}
		cout<<l-i<<" ";
	}
	return 0;
}