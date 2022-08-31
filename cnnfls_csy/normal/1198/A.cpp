#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
const int inf=1e9+7;
int n,m,i,j,x,ans;
string st;
vector<pair<int,int> > v,v2;
int f(int x)
{
	int s=1;
	x=min(x,50);
	while(x--){
		s=min(inf,s*2);
	}
	return s;
}
int main()
{
	scanf("%d%d",&n,&m);
	m=f(m*8/n);
	fz1(i,n){
		int x;
		scanf("%d",&x);
		v.push_back(make_pair(x,1));
	}
	sort(v.begin(),v.end());
	ff(v,it){
		if(v2.empty()||v2.back().first!=it->first){
			v2.push_back(*it);
		}
		else{
			v2.back().second++;
		}
	}
	int s=0;
	v=v2;
	j=0;int sum=0;
	fz0k(i,v.size()){
		while(j<v.size()&&j<i+m){
			sum+=v[j++].second;
		}
		ans=max(ans,sum);
		sum-=v[i].second;
	}
	cout<<n-ans<<endl;
	return 0;
}