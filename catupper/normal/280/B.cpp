#include<iostream>

#include<algorithm>

using namespace std;

int s[105000], n;

int solve(int left, int right){
    if(left >= right - 1)return -1;
    if(left == right - 2)return s[left] ^ s[right - 1];
    int n1, n2;
    int mid = (left + right) / 2;
    int tl = mid - 1, tr = mid;
    int res = s[tl] ^ s[tr];
    n1 = s[tl], n2 = s[tr];
    while(tl >= left && tr < right){
	if(n1 < n2){
	    while(tl >= left && s[tl] <= n1)tl--;
	    if(tl >= left)n1 = s[tl];
	    else break;
	    res = max(res, n1 ^ n2);
	}
	else{
	    while(tr < right && s[tr] <= n2)tr++;
	    if(tr < right)n2 = s[tr];
	    else break;
	    res = max(res, n1 ^ n2);
	}
    }
    res = max(res, solve(left, mid));
    res = max(res, solve(mid, right));
    return res;
}


int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
	cin >> s[i];
    }
    cout << solve(0, n) << endl;
    return 0;
}