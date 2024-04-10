#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int n, m;
vector<int>	vec;

void init(){
	if (m % 2 == 1){
		int mid = (m/2) + 1;
		for (int i = 0; i <= m / 2; i++){
			if (i == 0)
				vec.push_back(mid);
			else{
				vec.push_back(mid - i);
				vec.push_back(mid + i);
			}
		}
	}
	else{
		int mid = m/2;
		for (int i = 0; i < m/2; i++){
			vec.push_back(mid - i);
			vec.push_back(mid + i + 1);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	init();
	int ind = 0;
	for (int i = 0; i < n; i++, ind++)
		printf("%d\n", vec[ind % m]);
	return 0;
}