#include<iostream>
#include<algorithm>

using namespace std;

int match[1050000];

int main(){
    int n;
    fill(match, match + 1050000, -1);
    cin >> n;
    int p = (1 << 29) - 1;
    long long  res = 0;
    for(int i = n;i > 0;i--){
	if(match[i] != -1)continue;
	while(p >> 1 >= i)p>>=1;
	match[i] = p ^ i;
	match[p ^ i] = i;
	res += p * 2;
    }
    if(match[0] == -1)match[0] = 0;
    cout << res << endl;
    for(int i = 0;i <= n;i++){
	cout << match[i];
	if(i != n)cout << ' ';
    }
    cout << endl;
    return 0;
}