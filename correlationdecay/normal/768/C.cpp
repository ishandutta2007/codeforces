#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#define maxn 1300
using namespace std;
int a[100009];
int cnt[maxn];
int b[maxn];
int main(){
	int n, k, x;
	cin >> n >> k >> x;
	int ma = -1, mi = 100000;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for(int i = 0; i < k; i++){
		memset(b, 0 ,sizeof(b));
		int last = 0;
		for(int j = 0; j < 1024; j++){
			if(last % 2 == 0){
				b[j ^ x] += (cnt[j] + 1) / 2;
				b[j] += cnt[j] / 2;
			}
			else{
				b[j ^ x] += cnt[j] / 2;
				b[j] += (cnt[j] + 1) / 2;
			}
			last += cnt[j];
		}
		for(int j = 0 ; j < 1024; j++)
			cnt[j] = b[j];
	}
	for(int i = 0 ; i < 1024; i ++){
		if(cnt[i]){
			mi = min(mi, i);
			ma = max(ma, i);
		}
	}
	cout << ma << " " << mi << endl;
	return 0;
}