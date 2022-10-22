/*




D P 




 l l
*/
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
char _buf_[1<<23],*_st_,*_ed_;
#define getchar() (_st_==_ed_&&(_ed_=(_st_=_buf_)+fread(_buf_,1,1<<23,stdin),_st_==_ed_)?-1:*_st_++)
int read(int &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
const int N=1000000;
int n;
pair<int,int> a[N+1];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=n;i++)a[i].X=lower_bound(nums.begin(),nums.end(),a[i].X)-nums.begin();
}
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.X==y.X)return x.Y<y.Y;
	return x.X>y.X;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i].X),a[i].Y=i,nums.pb(a[i].X);
	discrete();
	sort(a+1,a+n+1,cmp);
	set<int> st1;
	set<int,greater<int> > st2;
	int ans=0;
	for(int i=1,ie;i<=n;i=ie+1){
		ie=i;while(ie+1<=n&&a[i].X==a[ie+1].X)ie++;
		if(i==1)ans+=(ie-i+1)*(ie-i)>>1;
		else{
			if(i==2)ans+=ie-i+1;
			else if(i>2)ans+=ie-i+1<<1;
			vector<int> pos;
			for(int j=i;j<=ie;j++)pos.pb(a[j].Y-n);
			for(int j=i;j<=ie;j++)pos.pb(a[j].Y);
			for(int j=i;j<=ie;j++)pos.pb(a[j].Y+n);
			int add=0;
			int fst=pos.size()/3,las=pos.size()/3*2;
			for(int j=fst;j<las;j++){
				set<int>::iterator fd2=st1.lower_bound(pos[j]),fd1=st2.lower_bound(pos[j]);
				int l,r;
				if(fd2==st1.end())r=*st1.begin()+n;else r=*fd2;
				if(fd1==st2.end())l=*st2.begin()-n;else l=*fd1;
				add+=upper_bound(pos.begin(),pos.end(),r)-lower_bound(pos.begin(),pos.end(),l)-1;
			}
			ans+=add/2;
		}
		for(int j=i;j<=ie;j++)st1.insert(a[j].Y),st2.insert(a[j].Y);
//		cout<<a[i].X<<" "<<a[i].Y<<" "<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
/*1
5
1 2 4 5 3
*/