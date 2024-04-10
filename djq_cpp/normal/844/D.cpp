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
int val[50005],nxt[50005],q[50005];
map<int,int> id;
int main(){
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,s,x,cur;
	cin>>n>>s>>x;
	cout<<"? "<<s<<endl<<flush;
	cin>>val[s]>>nxt[s];
	id[val[s]]=s;
	rep(k,n)q[k]=k+1;
	rep1(k,n)nxt[k]=-2;
	random_shuffle(q,q+n);
	random_shuffle(q,q+n);
	rep(k,min(n,800)){
		cur=q[k];
		if(cur==s)continue;
		cout<<"? "<<cur<<endl<<flush;
		cin>>val[cur]>>nxt[cur];
		id[val[cur]]=cur;
	}
	map<int,int>::iterator it=id.lower_bound(x);
	if(it!=id.begin())it--;
	cur=it->second;
	while(cur!=-1){
		if(nxt[cur]==-2){
			cout<<"? "<<cur<<endl<<flush;
			cin>>val[cur]>>nxt[cur];
		}
		if(val[cur]>=x){
			cout<<"! "<<val[cur]<<endl<<flush;
			return 0;
		}
		cur=nxt[cur];
	}
	cout<<"! -1"<<endl<<flush;
	return 0;
}