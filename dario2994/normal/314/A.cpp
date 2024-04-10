#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

LL bah;
ULL N;
ULL k;

int main(){
	ios_base::sync_with_stdio(false);
	//~ ifstream cin("input.txt");
	cin >> N >> bah;
	k=-bah;
	ULL sum=0;
	ULL a;
	vector <int> res;
	ULL it=0;
	for(ULL i=1;i<=N;i++){
		cin >> a;
		//~ cout << i << " " << sum << "\n";
		it++;
		if(sum+k<(it-1)*((N-(i-it))-it)*a){
			res.push_back(i);
			it--;
		}
		else{
			sum+=a*(it-1);
		}
	}
	
	//~ cout << k << "\n";
	//~ cout << res.size() << "\n";
	for(int i=0;i<int(res.size());i++)cout << res[i] << "\n";
	//~ cout << "\n";
}