#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[105000], n, num, res = 1;


int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
	cin >> num;
	if(num == 1)continue;
	vector<int> divisor;
	int r = -1;
	for(int i = 2;num != 1;i++){
	    if(i * i > num){
		r = max(r, dp[num]);
		divisor.push_back(num);
		break;
	    }
	    if(num % i == 0){
		divisor.push_back(i);
		r = max(r, dp[i]);
		while(num % i == 0)num /= i;
	    }
	}
	r++;
	res = max(res, r);
	for(int i = 0;i < divisor.size();i++){
	    dp[divisor[i]] = r;
	}
    }        
    cout << res << endl; 
    return 0;
}