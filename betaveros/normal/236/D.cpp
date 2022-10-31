#include <iostream>
using namespace std;
typedef long long int lli;
#define BIG 100001

double prob[BIG];


double rightends(int low, int hi){ // empty, half-open
	//cout << "Right " << low << " " << hi << endl;
	if (hi - low == 0) return 0.0;
	double sum = prob[low];
	for (int i = low+1; i < hi; i++){
		sum = (sum + 1) * prob[i];
	}
	return sum;
}
double leftends(int low, int hi){
	//cout << "Left " << low << " " << hi << endl;
	if (hi - low == 0) return 0.0;
	double sum = prob[hi-1];
	for (int i = hi - 2; i >= low; i--){
		sum = (sum + 1) * prob[i];
	}
	return sum;
}
double interior(int low, int hi){ // nonempty, half-open, len2+
	if (hi - low <= 1) return 0.0;
	if (hi - low == 2) return prob[low] * prob[low+1];
	int mid = (hi + low) / 2;
	double ret = interior(low, mid) + interior(mid, hi) + rightends(low, mid) * leftends(mid, hi);
	//cout << "Interior " << low << " " << hi << " = " << ret;
	return ret;
}

int main(){
	int n;
	cin >> n;
	double sum;
	for (int i = 0; i < n; i++){
		cin >> prob[i];
		sum += prob[i];
	}
	//cout << sum << endl;
	cout.precision(15);
	cout << 2 * interior(0, n) + sum;

	
}