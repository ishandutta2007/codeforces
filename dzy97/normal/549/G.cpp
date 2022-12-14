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
const int mo = 1e9 + 7,N=2e5+10;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
int a[N],b[N],c[N],n;
int cmp(int i,int j){return a[i]+i<a[j]+j;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++) c[i]=a[b[i]]+b[i]-i;
	int fail=0;
	for(int i=2;i<=n;i++) if(c[i]<c[i-1]) fail=1;
	if(fail) printf(":(\n"); else for(int i=1;i<=n;i++) printf("%d%c",c[i],(i<n)?' ':'\n');
	return 0;
}