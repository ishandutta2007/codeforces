#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
double h;

int main(){
	scanf("%d%lf", &n, &h);
	double rh = h;
	double d = h / (2. * n);
	double l = 1;
	double cnt = 0;
	vector<double> ans;
	for(int i = 1; i < n; ++i){
		double lt = 0, rt = h;
		for(int j = 1; j <= 1000; ++j){
			double md = (lt + rt) / 2;
			double len = (1 - md / h) * l;
			double s = (len + l) * md / 2;
			if(s >= d) rt = md;
			else lt = md;
		}
		
		l = (1 - rt / h) * l;
		h -= rt;
		cnt += rt;
		ans.pb(cnt);
	}
	reverse(all(ans));
	for(auto v : ans)
		printf("%.10f ", rh - v);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}