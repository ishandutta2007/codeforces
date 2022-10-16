#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
int const MM = 1e4+5;

int askand(int i, int j){
	cout<<"and "<<i<<' '<<j<<endl;
	int x;
	cin>>x;
	return x;
}

int askor(int i, int j){
	cout<<"or "<<i<<' '<<j<<endl;
	int x;
	cin>>x;
	return x;
}

int sec[] = {0,1,6,4,2,3,5,4};

int ask(int i, int j){
	#ifdef LOCAL
	assert(i > 0 and i <= 7);
	assert(j > 0 and j <= 7);
	return sec[i]+sec[j];
	#endif
	return askand(i, j) + askor(i, j);
}

int n, k;
ll s[MM];

void out(){
	#ifdef LOCAL
	for(int i = 1; i <= n; i++)
		cerr<<s[i]<<' ';
	cerr<<endl;
	#endif
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	#ifdef LOCAL
	n = 7, k = 6;
	#else
	cin>>n>>k;
	#endif

	ll ab = ask(1, 2);
	ll bc = ask(2, 3);
	ll ac = ask(1, 3);
	ll a = ab-bc+ac;
	assert(a%2 == 0);
	// pr(ab, bc, ac, a);
	a /= 2;
	s[1] = a;
	s[2] = ab-a;
	s[3] = bc-s[2];
	for(int i = 4; i <= n; i++){
		s[i] = ask(i-1, i) - s[i-1];
	}
	out();
	sort(s+1, s+1+n);
	cout<<"finish "<<s[k]<<'\n';
	out();
}