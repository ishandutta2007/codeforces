#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2.5e5+5;
const int inf=0x3f3f3f3f;
int n,m;
struct sgt{
	int l,r,ls,rs;
	int mn1,mn2;
}s[3*N];
int rt,P;
inline void upd(int p){
	s[p].mn1=min(s[s[p].ls].mn1,s[s[p].rs].mn1);
	s[p].mn2=min(s[s[p].ls].mn2,s[s[p].rs].mn2);
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	s[p].mn1=s[p].mn2=inf;
	s[p].ls=s[p].rs=0;
	if(l==r) return p;
	int mid=l+r>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	return p;
}
void chg1(int p,int pos,int x){
	if(s[p].l==s[p].r){
		s[p].mn1=x;
		return;
	}
	int mid=s[p].l+s[p].r>>1;
	if(pos<=mid) chg1(s[p].ls,pos,x);
	else chg1(s[p].rs,pos,x);
	upd(p);
}
void chg2(int p,int pos,int x){
	if(s[p].l==s[p].r){
		s[p].mn2=x;
		return;
	}
	int mid=s[p].l+s[p].r>>1;
	if(pos<=mid) chg2(s[p].ls,pos,x);
	else chg2(s[p].rs,pos,x);
	upd(p);
}
int qry1(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r)
		return s[p].mn1;
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid) return qry1(s[p].ls,l,r);
	else if(l>mid) return qry1(s[p].rs,l,r);
	else return min(qry1(s[p].ls,l,mid),qry1(s[p].rs,mid+1,r));
}
int qry2(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r)
		return s[p].mn2;
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid) return qry2(s[p].ls,l,r);
	else if(l>mid) return qry2(s[p].rs,l,r);
	else return min(qry2(s[p].ls,l,mid),qry2(s[p].rs,mid+1,r));
}
int a[N];
int s1[N],s2[N],t1,t2;
int dp[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		P=0;
		rt=build(1,n);
		t1=n+1;t2=n+1;
		s1[t1]=s2[t2]=n+1;
		dp[n]=0;
		s1[--t1]=s2[--t2]=n;
		chg1(rt,n,0);
		chg2(rt,n,0);
		for(i=n-1;i>=1;i--){
			while(t1<=n&&a[i]<a[s1[t1]]) t1++;
			while(t2<=n&&a[i]>a[s2[t2]]) t2++;
			if(s1[t1]<s2[t2]){
				int r=lower_bound(s1+t1,s1+n+1,s2[t2])-s1-1;
				dp[i]=qry1(rt,t1,r)+1;
			}
			else{
				int r=lower_bound(s2+t2,s2+n+1,s1[t1])-s2-1;
				dp[i]=qry2(rt,t2,r)+1;
			}
			s1[--t1]=s2[--t2]=i;
			chg1(rt,t1,dp[i]);
			chg2(rt,t2,dp[i]);
		}
		cout<<dp[1]<<endl;
	}
	return 0;
}