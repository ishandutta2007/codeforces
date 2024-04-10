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
vector<pii> diff[100005][20];
int situ[100005][20],appe[100005][20];
ll cnt[100005][26],tree[262144];
int S[100005];
//len==0 => unit string
void get_diff(int mid,int len) {
	int ml=mid-(1<<(len-1)),mr=mid+(1<<(len-1));
	appe[mid][len]=appe[ml][len-1]|appe[mr][len-1];
	if(situ[ml][len-1]==-1||situ[mr][len-1]==-1||(situ[ml][len-1]==1&&situ[mr][len-1]==1)||
	        situ[mid][len-1]==-1) {
		situ[mid][len]=-1;
		return;
	}
	if(situ[ml][len-1]==0&&situ[mr][len-1]==0) {
		if(S[ml]==S[mr]) {
			if(situ[mid][len-1]==1&&diff[mid][len-1][0].first!=mid)situ[mid][len]=-1;
			else {
				situ[mid][len]=1;
				rep(k,26)if(!(appe[mid][len]>>k&1)) {
					if(k==S[mid])situ[mid][len]=0;
					else diff[mid][len].push_back(MP(mid,k));
				}
			}
		} else {
			situ[mid][len]=-1;
			if(situ[mid][len-1]==0) {
				if(S[mr]!=S[mid]) {
					situ[mid][len]=1;
					diff[mid][len].push_back(MP(ml,S[mr]));
				}
				if(S[ml]!=S[mid]) {
					situ[mid][len]=1;
					diff[mid][len].push_back(MP(mr,S[ml]));
				}
			}
		}
	} else if(situ[ml][len-1]==1) {
		if(diff[ml][len-1][0].first==ml) {
			if(situ[mid][len-1]==0&&!(appe[ml][len-1]>>S[mr]&1)&&S[mid]!=S[mr]) {
				situ[mid][len]=1;
				diff[mid][len].push_back(MP(ml,S[mr]));
			} else situ[mid][len]=-1;
		} else if(S[ml]!=S[mr]||S[mr]==S[mid])situ[mid][len]=-1;
		else {
			situ[mid][len]=-1;
			if(diff[ml][len-1][0].first!=ml) {
				if(situ[mid][len-1]==1) {
					if(diff[mid][len-1][0].first!=mid)
						rep(i,diff[ml][len-1].size())rep(j,diff[mid][len-1].size())
						if(diff[ml][len-1][i]==diff[mid][len-1][j]) {
							situ[mid][len]=1;
							diff[mid][len].push_back(diff[mid][len-1][j]);
						}
				} else rep(k,diff[ml][len-1].size())
					if(diff[ml][len-1][k].first<ml) {
						situ[mid][len]=1;
						diff[mid][len].push_back(diff[ml][len-1][k]);
					}
			}
		}
	} else if(situ[mr][len-1]==1) {
		if(diff[mr][len-1][0].first==mr) {
			if(situ[mid][len-1]==0&&!(appe[mr][len-1]>>S[ml]&1)&&S[mid]!=S[ml]) {
				situ[mid][len]=1;
				diff[mid][len].push_back(MP(mr,S[ml]));
			} else situ[mid][len]=-1;
		} else if(S[ml]!=S[mr]||S[ml]==S[mid])situ[mid][len]=-1;
		else {
			situ[mid][len]=-1;
			if(diff[mr][len-1][0].first!=mr) {
				if(situ[mid][len-1]==1) {
					if(diff[mid][len-1][0].first!=mid)
						rep(i,diff[mr][len-1].size())rep(j,diff[mid][len-1].size())
						if(diff[mr][len-1][i]==diff[mid][len-1][j]) {
							situ[mid][len]=1;
							diff[mid][len].push_back(diff[mid][len-1][j]);
						}
				} else rep(k,diff[mr][len-1].size())
					if(diff[mr][len-1][k].first>mr) {
						situ[mid][len]=1;
						diff[mid][len].push_back(diff[mr][len-1][k]);
					}
			}
		}
	}
	appe[mid][len]|=1<<S[mid];
}
ll query(int id) {
	id+=131072;
	ll ans=tree[id];
	id>>=1;
	while(id>0) {
		ans+=tree[id];
		id>>=1;
	}
	return ans;
}
void add(int l,int r,ll v) {
	l+=131072;
	r+=131072;
	while(l<r) {
		if(l&1)tree[l]+=v;
		if(!(r&1))tree[r]+=v;
		l=(l+1)>>1;
		r=(r-1)>>1;
	}
	if(l==r)tree[l]+=v;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string in;
	cin>>in;
	int n=in.length();
	ll ans=0LL;
	rep(k,n)S[k]=in[k]-'a';
	rep(i,n) {
		situ[i][0]=0;
		rep(j,26)if(j!=S[i]) {
			diff[i][0].push_back(MP(i,j));
			cnt[i][j]++;
		}
		appe[i][0]=1<<S[i];
		add(i,i,1LL);
		ans++;
	}
	rep1(i,16)rep(j,n) {
		if(j-(1<<i)<-1||j+(1<<i)>n)continue;
		get_diff(j,i);
		if(situ[j][i]==-1)continue;
		ll w=(1LL<<(i+i+2))-(1LL<<(i+2))+1;
		rep(k,diff[j][i].size())
		cnt[diff[j][i][k].first][diff[j][i][k].second]+=w;
		if(situ[j][i]==0){
			add(j-(1<<i)+1,j+(1<<i)-1,w);
			ans+=w;
		}
	}
	ll plu=0LL;
	rep(i,n)rep(j,26)plu=max(plu,cnt[i][j]-query(i));
	cout<<ans+plu<<'\n';
	return 0;
}