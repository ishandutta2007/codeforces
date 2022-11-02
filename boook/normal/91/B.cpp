#include<iostream>
using namespace std;
#define MAX 200000
int n , N;
int x[MAX] , pr[MAX];
int main()
{
	
	cin >> n;
	for(int i = 0 ; i < n ; i ++) cin >> x[i];
	pr[n - 1] = x[n - 1];
	for(int i = n - 2 ; i >= 0 ; i --) pr[i] = min(pr[i + 1] , x[i]);
	for(int i = 0 ; i < n ; i++) {
		int now = n - 1;
		if(x[now] < x[i]){
			cout << now - i - 1 << " ";
			continue;
		}
		for(int j = 27 ; j >= 0 ; j--){
			int tmp = now - (1 << j);
			if(tmp >= 0 && pr[tmp] >= x[i]) now = tmp;
		}
		now --;
		if(now < i) cout << -1 << " ";
		else cout << now - i - 1 << " "; 
	}
  return 0;
}