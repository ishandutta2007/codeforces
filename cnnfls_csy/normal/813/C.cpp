#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <map>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <fenv.h>
#define mp make_pair
#define fs first
#define se second
#define memset(a,t) memset(a,t,sizeof(a))
#define all(v) v.begin(),v.end()
#define N 200005
using namespace std;
vector<int> v[N];
int n,k;
int l[N];
int f[N];
int w[N];
inline void dfs(int dp){
	w[dp]=l[dp];
	for(int i=0;i<v[dp].size();i++){
		if(v[dp][i]!=f[dp]){
			f[v[dp][i]]=dp;
			l[v[dp][i]]=l[dp]+1;
			dfs(v[dp][i]);
			w[dp]=max(w[dp],w[v[dp][i]]);
		}
	}
}
int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	int i,x,y,ans;
	k--,n--;
	for(i=0;i<n;i++){
		cin>>x>>y;
		y--,x--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	f[0]=-1;
	dfs(0);
	ans=k;
	while(l[ans]-1>l[k]-l[ans]+1) ans=f[ans];
	cout<<2*w[ans]<<endl;
	return 0;
}