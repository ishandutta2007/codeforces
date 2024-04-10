#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, k;	cin >> n >> k;
	vector<int>	vec(n), mark(n, 0);
	for (int i = 0; i < n; i++)	cin >> vec[i];

	int ans = 0;
	for (int i = 0; i < 8 * n; i++){
		int maxi = -1, ind = -1;
		for (int j = 0; j < n; j++)
			if (maxi < vec[j]){
				maxi = vec[j];
				ind = j;
			}
		
		if (mark[ind] == 3){
			ans += vec[ind];
			vec[ind] = 0;
		}
		else{
			if (vec[ind] < k){
				ans += vec[ind];
				vec[ind] = 0;
			}
			else
				vec[ind] -= k;
			mark[ind]++;
		}
	}
	cout << ans << endl;
	return 0;
}