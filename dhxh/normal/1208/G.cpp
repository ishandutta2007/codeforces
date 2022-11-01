#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e6 + 5;

int n, m;

long long prime[maxn / 10];
bool isnp[maxn];
long long phi[maxn];
int pc = 0;
vector <int> vec;

int init(){
	long long i, j;
	
	phi[0] = 0;
	phi[1] = 1;
	
	for(i=2;i<=n;i++){
		if(!isnp[i]){
			pc++;
			prime[pc] = i;
			phi[i] = i - 1;
		}
		
		for(j=1;j<=pc and i * prime[j]<=n;j++){
			isnp[i * prime[j]] = true;
			if(i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}else{
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	}
	
	return 0;
}

int main(){
	int i, j;
	long long ans = 0;
	
	cin >> n >> m;
	
	init();
	
	for(i=3;i<=n;i++){
		vec.push_back(phi[i]);
	}
	
	sort(vec.begin(), vec.end());
	
	for(i=0;i<m;i++){
		ans += vec[i];
	}
	
	if(m == 1)ans += 1;
	else ans += 2;
	
	cout << ans << endl;
	
	return 0;
}