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
char str[105][105];
int n,m,a[105][105];
int main(){
	scanf("%d%d",&n,&m);
	int ret=0;
	for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
	for(int i=n;i;i--){
		for(int j=m;j;j--){
			int sum=0;
			for(int k=i;k<=n;k++){
				for(int l=j;l<=m;l++){
					if(k==i&&j==l) continue;
					sum+=a[k][l];
				}
			}
			int v=(str[i][j]=='W')?1:-1;
			if(sum!=v){
				ret++;
				a[i][j]=v-sum;
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}