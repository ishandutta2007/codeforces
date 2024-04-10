#include<iostream>  
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long Int;
typedef pair<int, double> P;

vector<double > vals;

#define abs(x) ((x) < 0?(-(x)):(x))
Int n, a[216000];

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		a[i] += a[i-1];
	}
	vector<P> lower, upper;
	lower.push_back(P(0, -10001));
	upper.push_back(P(0, 10001));
	for(int i = 1;i <= n;i++){
		while(true){
			P tmp = lower.back();
			double p = tmp.second;
			int ind = tmp.first;
			if(lower.size() > 1 && a[i] - i * p < a[ind] - ind * p)lower.pop_back();
			else{
				double t = (double)(a[i] - a[ind]) / (i - ind);
				lower.push_back(P(i, t));
				break;
			}
		}
		while(true){
			P tmp = upper.back();
			double p = tmp.second;
			int ind = tmp.first;
			if(upper.size() > 1 && a[i] - i * p > a[ind] - ind * p)upper.pop_back();
			else{
				double t = (double)(a[i] - a[ind]) / (i - ind);
				upper.push_back(P(i, t));
				break;
			}         
		}

	}
	for(int i = 0;i < lower.size();i++){
		vals.push_back(lower[i].second);
	}
	for(int i = 0;i < upper.size();i++){
		vals.push_back(upper[i].second);                                
	}
	sort(vals.begin(), vals.end());	
	int lpos = 0, upos = upper.size() - 1;
	double ans = 1e18;
	double res;
	for(int i = 0;i < vals.size();i++){
		while(upos >= 0 && upper[upos].second < vals[i])upos--;
		while((lpos + 1) < lower.size() && lower[lpos + 1].second < vals[i])lpos++;
		int lind = lower[lpos].first;
		int uind = upper[upos].first;
		double tmp = (a[uind] - uind * vals[i]) - (a[lind] - lind * vals[i]);
		if(tmp < ans){
			res = vals[i];
			ans = tmp;
		}
	}
	printf("%.10lf\n", ans);
	return 0;
}