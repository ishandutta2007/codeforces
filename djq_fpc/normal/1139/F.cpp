#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))],
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,p[100005],s[100005],b[100005],inc[100005],pref[100005],ans[100005],ss[200005],sizy,sizz;
struct ii{char op;int x,y,z,val,id;};
vector<ii> v;
vector<int> all;
bool cmp(ii x,ii y)
{
	if(x.x==y.x)return x.op<y.op;
	return x.x<y.x; 
}
void add(int x,int y)
{
	int i;for(i=x;i<=sizz;i+=(i&-i))ss[i]+=y;
}
int query(int x)
{
	int i,sum=0;for(i=x;i;i-=(i&-i))sum+=ss[i];return sum;
}
void solve(vector<ii> v,int l,int r)
{
	if(l==r)return;if(v.empty())return;
	int mid=(l+r)/2;vector<ii> vl,vr;
	ff(v,it){
		if(it->y<=mid){
			vl.push_back(*it);
			if(it->op==0){
				add(it->z,it->val);
			}
		}
		else{
			vr.push_back(*it);
			if(it->op==1){
				ans[it->id]+=it->val*query(it->z);
			}
		}
	}
	ff(v,it){
		if(it->y<=mid){
			if(it->op==0){
				add(it->z,-it->val);
			}
		}
	}
	solve(vl,l,mid);solve(vr,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n)scanf("%d",&p[i]);fz1(i,n)scanf("%d",&s[i]);fz1(i,n)scanf("%d",&b[i]);
	fz1(i,m)scanf("%d",&inc[i]);fz1(i,m)scanf("%d",&pref[i]);
	fz1(i,n){
		v.push_back((ii){0,s[i]+1,b[i]+p[i],p[i]-b[i],-1,0});
		v.push_back((ii){0,p[i],b[i]+p[i],p[i]-b[i],1,0});
	}
	fz1(i,m){
		v.push_back((ii){1,inc[i],inc[i]+pref[i]+1,inc[i]-pref[i],1,i});
	}sort(v.begin(),v.end(),cmp);
	/*ff(v,it){
		cerr<<it->op<<' '<<it->x<<' '<<it->y<<' '<<it->z<<' '<<it->val<<' '<<it->id<<endl;
	}*/
	fz0k(i,v.size())all.push_back(v[i].y);
	sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
	fz0k(i,v.size())v[i].y=upper_bound(all.begin(),all.end(),v[i].y)-all.begin();sizy=all.size();
	all.clear();fz0k(i,v.size())all.push_back(v[i].z);
	sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
	fz0k(i,v.size())v[i].z=upper_bound(all.begin(),all.end(),v[i].z)-all.begin();sizz=all.size();
	solve(v,1,sizy);
	fz1(i,m){
		printf("%d ",ans[i]);
	}
	return 0;
}