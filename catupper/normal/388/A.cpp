#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n, num[105];
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num[i];
	}
	sort(num, num + n);
	int cnt = n, res = 0;;
	while(cnt){
		int l = 0;
		for(int i = 0;i < n;i++){
			if(num[i] == -1)continue;
			if(num[i] >= l){
				num[i] = -1;
				l++;
				cnt--;
			}
		}
		res++;
	}
	cout << res << endl;
	return 0;
}