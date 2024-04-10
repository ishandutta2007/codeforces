#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int prime(int x){
    if(x == 0)return 1;
    return x * prime(x - 1);
}

int al[1000];
int zero;
int main(){
    string str;
    int n;
    cin >> str;
    n = str.size();
    for(int i = 0;i < n;i++){
	if('A' <= str[i] && str[i] <= 'J'){
	    al[str[i] - 'A'] |= 1;
	}
	if(str[i] == '?'){
	    zero++;
	}
    }
    int sum = 0;
    for(int i = 0;i < 100;i++)sum += al[i];
    int res = prime(10) / prime(10 - sum);
    if(str[0] == '?' || 'A' <= str[0] && str[0] <= 'J'){
	res *= 9;
	if(zero)zero--;
	else res/=10;
    }
    cout << res << string(zero, '0') << endl;
    return 0;
}