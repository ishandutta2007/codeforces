#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if(k > n || k == 1 && n != 1){
	cout << -1 << endl;
	return 0;
    }

    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0;i < n;i++){
	if(i < n - k + 2){
	    cout << letters[i & 1];
	}
	else{
	    cout << letters[k - (n - i)];
	}
    }
    cout << endl;
    return 0;
}