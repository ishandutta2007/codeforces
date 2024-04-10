#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define MAX 200
int n , x[MAX] , ok[MAX];
vector<int> v[MAX];
int main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int sum = 0;
	REP(i , 1 , n + 1) sum += x[i];
	sum /= (n / 2);
	REP(i , 1 , n + 1){
		if(ok[i] == 0){
			ok[i] = 1;
			REP(j , i + 1 , n + 1){
				if(ok[j] == 0 && x[i] + x[j] == sum){
					ok[j] = 1;
					cout << i << " " << j << endl;
					break;
				}
			}
		}
	}
	return 0;
}