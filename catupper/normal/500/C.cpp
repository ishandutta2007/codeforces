#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int n, m;
int w[108000];
int b[108000];
vector<int> books;
bool used[108000];
int res;
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++)cin >> w[i];
	for(int i = 0;i < m;i++){
		cin >> b[i];b[i]--;
		if(!used[b[i]]){
			books.push_back(b[i]);
			used[b[i]] = true;
		}
	}
	for(int i = 0;i < m;i++){
		int now = 0;
		while(books[now] != b[i])now++;
		for(int j = now - 1;j >= 0;j--){
			res += w[books[j]];
			books[j+1] = books[j];
		}
		books[0] = b[i];
	}
	cout << res << endl;
	return 0;	
}