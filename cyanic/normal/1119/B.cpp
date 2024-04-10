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

const int N=10005;
int b[N],a[N],n,h;

int chk(int t){
	rep(i,1,t)a[i]=b[i];
	sort(a+1,a+t+1,greater<int>());
	ll sum=0;
	for(int i=1;i<=t;i+=2){
		sum+=a[i];
		if(sum>h)return 0;
	}
	return 1;
}

int main(){
	cin>>n>>h;
	rep(i,1,n)cin>>b[i];
	int l=0,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(chk(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}