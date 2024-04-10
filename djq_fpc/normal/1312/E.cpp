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
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int t,n,m,i,j,a[200005],ans,dp[200005];
set<pair<int,int> > cur,nxt;
vector<int> pos[1105],bi[200005];
int main()
{
	scanf("%d",&n);
	fz1(i,n){
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
	}
	fz1(i,1100){
		ff(pos[i],it) cur.insert(make_pair(*it,*it));
		ff(cur,it){
			bi[it->second].push_back(it->first-1);
			set<pair<int,int> >::iterator it2=cur.upper_bound(make_pair(it->second+1,0));
			if(it2==cur.begin()) continue;
			if(it->second+1==it2->first){
				nxt.insert(make_pair(it->first,it2->second));
			}
		}
		cur=nxt;nxt.clear();
	}
	dp[0]=0;
	fz1(i,n){
		dp[i]=0x3f3f3f3f3f;
		ff(bi[i],it){
			dp[i]=min(dp[i],dp[*it]+1);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}