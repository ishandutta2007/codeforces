#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#define open_in(n) freopen(n,"r",stdin)
#define open_out(n) freopen(n,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<=n;i++)
#define ALL(n) n.begin,n.end
#define SIZE(n) (int)(n.size())
#define ll long long
#define PB push_back
#define MP make_pair
#define IT iterator
using namespace std;
int num[60][60],ans[60],f[60];
int main(){
	int n,bt=-1;
	scanf("%d",&n);
	FOR(i,1,n)rep(j,n)
	scanf("%d",&num[i][j]);
	FOR(k,1,n){
		ans[k]=0;
		for(int i=0;i<n;i++)
		ans[k]=max(ans[k],num[k][i]);
		if(f[ans[k]])bt=k;
		f[ans[k]]=k;
	}
	FOR(k,1,n)
	if(!f[k]){
		ans[bt]=k;
		break;
	}
	FOR(k,1,n)
	printf("%d ",ans[k]);
	return 0;
}