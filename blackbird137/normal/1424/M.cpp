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
#pragma GCC optimize(3)
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
inline char readc() {
	register char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}
int n,k,p,cnt,in[30];
bool has[30],vis[30];
char s[1002][1002][102];
int len[1002][1002],l[1000002];
char str[102],ss[1000002][102];
vector<char>ans;
vector<int>g[30];
inline bool ok() {
	F(i,1,26) {
		if(in[i]==0&&(!vis[i])) {
			ans.push_back(i+'a'-1);
			F(j,0,g[i].size()-1)in[g[i][j]]--;
			vis[i]=1;
			return 1;
		}
	} return 0;
}
int main() {
	cin>>n>>k;
	F(i,1,n) {
		cin>>p;
		F(i,1,k) {
			scanf("%s",s[p][i-1]);
			len[p][i-1]=strlen(s[p][i-1]);
//			F(ii,0,len[p][i-1]-1)if(s[p][i-1][ii]>='A'&&s[p][i-1][ii]<='Z')return 123;
			F(ii,0,len[p][i-1]-1)has[s[p][i-1][ii]-'a'+1]=1;
		}
	}
	F(i,0,1000) {
		if(len[i][0])
		F(j,0,k-1) {
			strcpy(ss[++cnt],s[i][j]);
			l[cnt]=len[i][j];
		}
	}
	ri j;
	F(i,1,cnt-1) {
		for(j=0; j<min(l[i],l[i+1]); j++) {
			if(ss[i][j]!=ss[i+1][j]) {
				g[ss[i][j]-'a'+1].push_back(ss[i+1][j]-'a'+1);
				in[ss[i+1][j]-'a'+1]++;
				break;
			}
		}if(j==min(l[i],l[i+1])&&l[i]>l[i+1]){
				printf("IMPOSSIBLE");
			return 0;
			}
	}
	cnt=26;
	while(cnt--) {
		if(ok()) {
			
		} else {
			printf("IMPOSSIBLE");
			return 0;
		}

	}F(i,0,ans.size()-1){
		if(has[ans[i]-'a'+1])putchar(ans[i]);
	}

	return 0;
}