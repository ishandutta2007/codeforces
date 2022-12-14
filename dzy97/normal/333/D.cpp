#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <cstdlib>
#include <cassert>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define cl(x,a) memset(x,a,sizeof(x))
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

bitset<1001>b[1005];
int n,m,a[1005][1005],bin[1000010],cnt;
int check(int v){
	rep(i,1,n) b[i].reset();
	rep(i,1,n) rep(j,1,m) if(a[i][j]>=v) b[i].set(j);
	rep(i,1,n) rep(j,i+1,n) if((b[i]&b[j]).count()>=2) return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]),bin[++cnt]=a[i][j];
	sort(bin+1,bin+cnt+1);
	cnt=unique(bin+1,bin+cnt+1)-bin-1;
	int l=1,r=cnt,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(bin[mid])) l=mid+1; else r=mid-1;
	}
	printf("%d\n",bin[r]);
	return 0;
}