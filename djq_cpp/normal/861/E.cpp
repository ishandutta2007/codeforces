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
int n,sp;
bool have[200005];
pair<int,string> inp[100005];
vector<string> rst[2];
vector<int> rt[2],ft[2];
vector<pair<string,string> > ansv;
int TO_NUM(string S){
	if(S[0]=='0')return -1;
	int ans=0;
	rep(k,S.length()){
		if(S[k]<'0'||S[k]>'9')return -1;
		ans=ans*10+S[k]-'0';
	}
	return ans;
}
string TO_STR(int num){
	string res;
	do{
		res.push_back(num%10+'0');
		num/=10;
	}while(num);
	reverse(res.begin(),res.end());
	return res; 
}
void MOVE(int f,int t){
	have[f]=false;
	have[t]=true; 
}
int unused_str(){
	rep(k,200000)
	if(!have[k])return k;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	rep(k,n){
		cin>>inp[k].second>>inp[k].first;
		sp+=inp[k].first;
	}
	rep(k,n){
		int num=TO_NUM(inp[k].second);
		if(num>=0&&num<200000)have[num]=true;
		if(num>n||num<=0)rst[inp[k].first].push_back(inp[k].second);
		else{
			if((num<=sp)==inp[k].first)rt[inp[k].first].push_back(num);
			else ft[inp[k].first].push_back(num);
		}
	}
	int from=-1,cur=-1;
	rep1(k,sp)if(!have[k]){
		from=1;
		cur=k;
	}
	if(cur==-1)for(int k=sp+1;k<=n;k++)
	if(!have[k]){
		from=0;
		cur=k;
	}
	if(cur==-1){
		int S=unused_str();
		if(!ft[0].empty()){
			MOVE(ft[0].back(),S);
			ansv.push_back(MP(TO_STR(ft[0].back()),TO_STR(S)));
			from=1;cur=ft[0].back();
			rst[0].push_back(TO_STR(S));
			ft[0].pop_back();
		}else if(!ft[1].empty()){
			MOVE(ft[1].back(),S);
			ansv.push_back(MP(TO_STR(ft[1].back()),TO_STR(S)));
			from=0;cur=ft[1].back();
			rst[1].push_back(TO_STR(S));
			ft[1].pop_back();
		}
	}
	for(int kk=from;!ft[kk].empty();kk^=1){
		MOVE(ft[kk].back(),cur);
		ansv.push_back(MP(TO_STR(ft[kk].back()),TO_STR(cur)));
		cur=ft[kk].back();
		ft[kk].pop_back();
	}
	for(int kk=1;kk<=sp;kk++)
	if(!have[kk]&&!ft[1].empty()){
		MOVE(ft[1].back(),kk);
		ansv.push_back(MP(TO_STR(ft[1].back()),TO_STR(kk)));
		ft[1].pop_back();
	}
	for(int kk=sp+1;kk<=n;kk++)
	if(!have[kk]&&!ft[0].empty()){
		MOVE(ft[0].back(),kk);
		ansv.push_back(MP(TO_STR(ft[0].back()),TO_STR(kk)));
		ft[0].pop_back();
	}
	for(int kk=1;kk<=sp;kk++)
	if(!have[kk]&&!rst[1].empty()){
		ansv.push_back(MP(rst[1].back(),TO_STR(kk)));
		rst[1].pop_back();
	}
	for(int kk=sp+1;kk<=n;kk++)
	if(!have[kk]&&!rst[0].empty()){
		ansv.push_back(MP(rst[0].back(),TO_STR(kk)));
		rst[0].pop_back();
	}
	cout<<ansv.size()<<'\n';
	rep(k,ansv.size())
		cout<<"move "<<ansv[k].first<<' '<<ansv[k].second<<'\n';
	return 0;
}