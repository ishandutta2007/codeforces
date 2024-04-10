#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n;
string call[108];
int need[108];
bool come[108];
int cnt;

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> call[i];
	}
	for(int i = 0;i < n;i++){
		cin >> need[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(need[j] == 0){
				come[j] = true;
				cnt++;
				for(int k = 0;k < n;k++){
					if(call[j][k] == '1')
						need[k]--;
				}
			}
		}
	}
	cout << cnt << endl;
	if(cnt == 0)cout << endl;
	for(int i = 0;i < n;i++){
		if(come[i])cout << i + 1 << endl;
	}
	return 0;
	
}