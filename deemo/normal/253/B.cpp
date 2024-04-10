#include<fstream>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int n;
vector<int>	vec;

int main(){
	fstream fin("input.txt");
	ofstream fout("output.txt");
	int n;	fin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
		fin >> vec[i];
	sort(vec.begin(), vec.end());	
	int ans = 1e9;
	for (int i = 0; i < n; i++){
		int t = n - i - 1;
		int pos = lower_bound(vec.begin(), vec.end(), ceil(double(vec[i])/ 2)) - vec.begin();
		t += pos;
		ans = min(ans, t);
	}
	fout << ans << endl;
	return 0;
}