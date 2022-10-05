#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=500005;
int a[N],b[N],q[N],l,r,n,ans,bas;

int sp(){
	int s=0;
	rep(i,1,n)
		if(b[i]==1)s=i;
	if(!s)return -1;
	rep(i,s,n)
		if(b[i]!=i-s+1)return -1;
	int t=b[n]+2;
	rep(i,1,s-1){
		if(b[i]&&b[i]<t)return -1;
		t++;
	}
	return s-1;
}

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	
	ans=sp();
	if(ans!=-1){
		cout<<ans<<endl;
		return 0;
	}

	int cnt0=0;
	rep(i,1,n)cnt0+=(a[i]==0);
	rep(i,1,n)if(b[i]){
		while(l<r&&b[i]-i<b[q[r-1]]-q[r-1])r--;
		q[r++]=i;
	}

	rep(i,0,n){
		while(l<r&&q[l]<=i)l++;
		int k=q[l];
		//flag|=(b[i]==1);
		if(l==r||k-i<b[k]){
			printf("%d\n",i+n);
			return 0;
		}
	}
	

	return 0;
}