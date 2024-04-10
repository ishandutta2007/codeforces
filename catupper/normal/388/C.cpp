#include<iostream>
#include<algorithm>

using namespace std;
int main(){
	int n, s, x;
	cin >> n;
	int c = 0, ji = 0;
	int centers[105];
	int p = 0;
	for(int i = 0;i < n;i++){
		cin >> s;
		for(int j = 0;j < s;j++){
			cin >> x;
			if(j < s / 2)c += x;
			else if(s % 2 == 1 && j == s / 2)centers[p++] = x; 
            else ji += x;
		}
	}
	sort(centers, centers + p);
	int t = 1;
	for(int i = p - 1;i >= 0;i--){
		if(t)c += centers[i];
		else ji += centers[i];
		t = !t;
	}
	cout << c << " " << ji << endl;
	return 0;
}