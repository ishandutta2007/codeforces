#include<iostream>
#include<complex>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef complex<float> C;
#define N (1 << 21)
#define PI (3.1415926535897932384626433)
C ok[N], was[N], tmp[N];
int n, m, a;
vector<int> res;

void fft(C *nums, C *tmp, int n, float th){
	if(n == 1)return;
	for(int i = 0;i < n / 2;i++){
		tmp[i] = nums[i] + nums[i + n / 2];
		tmp[i + n / 2] = (nums[i] - nums[i + n / 2]) * C(cos(th * i), sin(th * i));
	}
	fft(tmp, nums, n / 2, th * 2);
	fft(tmp + (n / 2), nums, n / 2, th * 2);
	for(int i = 0;i < n / 2;i++){
		nums[2 * i] = tmp[i];
		nums[2 * i + 1] = tmp[n / 2 + i];
	}
}

int main(){
	cin >> n >> m; 
	for(int i = 0;i < n;i++){
		cin >> a;
		ok[a] = was[a] = 1;
	}        	
	fft(ok, tmp, N, 2 * PI / N);
	for(int i = 0;i < N;i++){
		ok[i] *= ok[i];
	}
	fft(ok, tmp, N, -2 * PI / N);
	for(int i = 0;i < N;i++)ok[i] = (int)(real(ok[i]) / N + 0.5);
	for(int i = 0;i <= m;i++){
		if(real(was[i]) == 0 && real(ok[i]) != 0 ){
			cout << "NO" << endl;
			return 0;
		}
		if(real(was[i]) != 0 && real(ok[i]) == 0){			
			res.push_back(i);
		}		
	}
	cout <<"YES" << endl;
	cout << res.size() << endl;
	for(int i = 0;i < res.size();i++){
		if(i)cout <<" ";
		cout << res[i];
	}
	cout << endl;
	return 0;                          
}