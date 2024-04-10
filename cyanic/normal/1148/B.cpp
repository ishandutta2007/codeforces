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

const int N=200005;
int a[N],b[N],n,m,ta,tb,k,mx;

int main(){
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d",&b[i]);
	if(k>=n||k>=m)return puts("-1"),0;
	int l=1,r;
	rep(i,0,k){
		while(l<=m&&b[l]<a[i+1]+ta)l++;
		r=l+k-i-1;
		if(r>=m)return puts("-1"),0;
		mx=max(mx,b[r+1]+tb);
	}
	cout<<mx<<endl;
	return 0;
}