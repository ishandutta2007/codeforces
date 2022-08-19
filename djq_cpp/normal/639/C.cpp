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
int n,L;
ll lim,a[200100],data[200100];
void transform(ll a,int p){
	ll cur=1LL;
	if(a<0LL){
		cur=-1LL;
		a=-a;
	}
	while(a>0LL){
		data[p++]+=(a&1LL)*cur;
		a>>=1;
	}
	L=max(L,p);
}
int main(){
	ll cur=0LL;
	scanf("%d%I64d",&n,&lim);
	for(int k=0;k<=n;k++){
		scanf("%I64d",&a[k]);
		transform(a[k],k);
	}
	for(int k=0;k<L;k++){
		if(data[k]<0){
			data[k+1]-=(-data[k]+1)>>1;
			data[k]&=1ll;
		}else{
			data[k+1]+=(data[k]>>1);
			data[k]&=1ll;
		}
		if(data[L]==-1){
			for(int k=0;k<=L;k++)data[k]=-data[k];
			for(int k=0;k<=n;k++)a[k]=-a[k];
			for(int k=0;k<L;k++)
			if(data[k]<0){
				data[k+1]--;
				data[k]&=1;
			}
			L++;
			break;
		}else if(data[L]!=0LL)L++;
	}
	int pos=0,ans=0;
	for(;pos<L&&data[pos]==0LL;pos++);
	pos=min(pos,n);
	for(int k=L-1;k>=pos;k--){
		cur=(cur<<1)+data[k];
		if(cur>>50){
			printf("0");
			return 0;
		}
	}
	if(a[pos]-cur<=lim&&a[pos]-cur>=-lim&&(pos!=n||cur-a[pos]!=0LL))ans++;
	for(int k=pos-1;k>=0;k--){
		cur<<=1;
		if(cur>>50)break;
		if(a[k]-cur<=lim&&a[k]-cur>=-lim)ans++;
	}
	printf("%d\n",ans);
	return 0;
}