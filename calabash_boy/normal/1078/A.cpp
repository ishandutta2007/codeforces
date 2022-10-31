// Created by calabash_boy on 18-10-18.
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif
#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)
#define range(x) x.begin(),x.end()
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
/************* header ******************/
db L(pair<db,db> a,pair<db,db> b){
	db dx = a.first - b.first;
	db dy = a.second - b.second;
	return sqrt(dx*dx + dy*dy);
}
int main(){
	db a,b,c;
	cin>>a>>b>>c;
	pair<db,db> S,T;
	cin>>S.first>>S.second;
	cin>>T.first>>T.second;
	db ans = abs(S.first - T.first) + abs(S.second - T.second);
	pair<db,db> S1,S2,T1,T2;
	if (a!=0 && b !=0){
		S1.first = S.first;
		S1.second = - (a*S1.first + c) / b;
		S2.second = S.second;
		S2.first = - (b*S2.second +c)/a;
		
		T1.first = T.first;
		T1.second = - (a * T1.first +c)/b;
		T2.second = T.second;
		T2.first = - (b*T2.second +c)/a;
		
	}else if (a == 0){
		S1.first = S.first;
		S2.first = S.first;
		T1.first = T.first;
		T2.first = T.first;
		S1.second = S2.second = T1.second = T2.second = -c/b;
	}else if (b == 0){
		S1.second = S2.second = S.second;
		T1.second = T2.second = T.second;
		S1.first = S2.first = T1.first = T2.first = -c/a;
	}else assert(0);
	
		ans = min(ans,L(S,S1) + L(S1,T1) +  L(T1,T));
		ans = min(ans,L(S,S1) + L(S1,T2) +  L(T2,T));
		ans = min(ans,L(S,S2) + L(S2,T1) +  L(T1,T));
		ans = min(ans,L(S,S2) + L(S2,T2) +  L(T2,T));
		
	printf("%.9f\n",ans);
	 
    return 0;
}