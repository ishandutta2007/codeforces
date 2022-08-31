#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
vector<int> eum;
int w[100005];
int Euler(int num){
	int p=2,ans=1;
	while(p*p<=num){
		int ct=1;
		while(num%p==0){
			ct*=p;
			num/=p;
		}
		if(ct>1)ct=ct/p*(p-1);
		ans*=ct;
		p++;
	}
	if(num>1)ans*=num-1;
	return ans;
}
ll power(int x,int t,ll m){
	if(t==0)return 1;
	long long cc=power(x,t>>1,m);
	cc=cc*cc%m;
	if(t&1)cc=cc*x%m;
	return cc;
}
int gcd(int m,int n){
	return n==0?m:gcd(n,m%n);
} 
int solve(int l,int r,int mid){
	if(l>r)return 1;
	if(eum[mid]==1)return 0;
	vector<int> cc;
	for(int k=l+1;k<=r&&k<=l+4;k++)cc.push_back(w[k]);
	cc.push_back(1);
	rep(k,cc.size())if(cc[k]==1){
		ll cur=1LL;
		for(int j=k-1;j>=0;j--){
			if(cc[j]>=30||cc[j]>=4&&cur>=4){
				cur=30LL;break;
			}
			cur=power(cc[j],cur,1LL<<62);
			if(cur>30LL){
				cur=30LL;break;
			}
		}
		if(cur<30LL)return power(w[l],cur,eum[mid])%eum[mid];
		else return power(w[l],solve(l+1,r,mid+1)+eum[mid+1],eum[mid]);
	}
}
int main(){
	int n,m,q,x,l,r;
	scanf("%d%d",&n,&m);
	eum.push_back(m);
	while((x=eum.back())>1)eum.push_back(Euler(x));
	rep(k,n)scanf("%d",&w[k]);
	scanf("%d",&q);
	rep(k,q){
		scanf("%d%d",&l,&r);l--;r--;
		printf("%d\n",solve(l,r,0));
	}
	return 0;
}