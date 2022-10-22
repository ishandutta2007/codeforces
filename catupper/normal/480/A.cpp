#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int, int> P;

P a[108000];
int n;


int main(){
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i].first >>a[i].second;
	sort(a, a + n);
	bool able = true;
	for(int i = 1;i < n;i++){
		bool tmp = false;
		if(a[i].second >= a[i-1].first || able && a[i].second >= a[i-1].second){
			tmp = true;
		}		
		able = tmp;
	}
	if(able){
		cout << min(a[n-1].first, a[n-1].second) << endl;
	}
	else{
		cout << a[n-1].first << endl;
	}
	return 0;
}