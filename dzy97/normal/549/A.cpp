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

int n,m;
char str[55][55],a[4];
int main(){
	scanf("%d%d",&n,&m);
	int ret=0;
	for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			a[0]=str[i][j];
			a[1]=str[i][j+1];
			a[2]=str[i+1][j];
			a[3]=str[i+1][j+1];
			sort(a,a+4);
			if(a[0]=='a'&&a[1]=='c'&&a[2]=='e'&&a[3]=='f') ret++;
		}
	}
	printf("%d\n",ret);


	return 0;
}