#include<iostream>
#include<algorithm>

using namespace std;
int n, m, k, cnt[2160];
char c;
int main(){
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> c;
			if(c == '.')continue;
			if(c == 'D')continue;
			if(c == 'U'){
				if(i % 2 == 0)
					cnt[j]++;
			}
			if(c == 'R'){
				if(j + i < m)cnt[j + i]++;
			}
			if(c == 'L'){
				if(j - i >= 0)cnt[j - i]++;
			}
		}
	}	
	for(int i = 0;i < m;i++){
		if(i)cout << " ";
		cout << cnt[i];
	}
	cout << endl;
	return 0;
}