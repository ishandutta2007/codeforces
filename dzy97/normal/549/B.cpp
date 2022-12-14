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
const int mo = 1e9 + 7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

int n,a[105],c[105],ans[105],tot;
char str[105][105];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	while(1){
		int done=1;
		for(int i=1;i<=n;i++){
			if(c[i]==a[i]){
				done=0;
				ans[++tot]=i;
				for(int j=1;j<=n;j++) if(str[i][j]-48) c[j]++;
			}
		}
		if(done) break;
	}
	printf("%d\n",tot);sort(ans+1,ans+tot+1);
	if(tot>=1)printf("%d", ans[1]);
	for(int i=2;i<=tot;i++) printf(" %d", ans[i]);
	putchar('\n');
	return 0;
}