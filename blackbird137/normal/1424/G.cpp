//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
inline int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	return fu?-x:x;
}
inline char readc(){
	register char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}ll n,add[100002],mns[100002],now,p1,p2,cnt,ans1,ans2=-1;
pair<int,int>p[1000002];
inline bool cmp(pair<int,int>x,pair<int,int>y){
	return x.first<y.first;
}
int main(){
    cin>>n;
    F(i,1,n){
    	p[++cnt].first=read();
    	p[cnt].second=1;
    	p[++cnt].first=read();
    	p[cnt].second=-1;
	}sort(p+1,p+cnt+1,cmp);
	F(i,1,cnt){
		now+=p[i].second;
		if(p[i].first!=p[i+1].first){
			if(now>ans2){
				ans1=p[i].first;
				ans2=now;
			}
		}
	}cout<<ans1<<' '<<ans2;
    return 0;
}