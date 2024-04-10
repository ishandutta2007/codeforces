#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define MOD 1000000009
#define PRIME 100000007

vector<long long> good;
long long n, r;
struct R{
    string str;
    long long l, r;
};
R rule[15];

long long pow(long long x, long long p, long long m){
    long long res = 1;
    if(p == 0)return 1;
    long long half = pow(x, p / 2, m);
    half *= half;
    half %= m;
    if(p & 1)half *= x;
    half += m;
    half %= m;
    return half;
}

bool ok(long long x, long long len, long long rulenum){
    long long cnt = 0;
    string &str = rule[rulenum].str;
//    cout << str << endl;
    if(str.size() < len){
	    return rule[rulenum].l <= cnt && cnt <= rule[rulenum].r;
    };
    long long p = 0;
    for(long long i = 0;i < len;i++){
	p *= PRIME;
	p %= MOD;
	p += str[i] - 'a' + 1;
	p %= MOD;
    }
    long long minu = pow(PRIME, len, MOD);
    for(long long i = 0;i + len <= str.size();i++){
//	cout << p <<" " << x << endl;
	if(p == x)cnt++;
	if(i + len == str.size())break;
	p *= PRIME;
	p %= MOD;
	p += str[i + len] - 'a' + 1;
	p -= (str[i] - 'a' + 1) * minu;
	p %= MOD;
	p += MOD;
	p %= MOD;
    }
    return rule[rulenum].l <= cnt && cnt <= rule[rulenum].r;
}

bool able(long long x, long long len){
    for(long long i = 0;i < r;i++){
	if(!ok(x, len, i))return false;
    }
    return true;
}

int main(){
    string str;
    cin >> str;
    n = str.size();
    cin >> r;
    for(long long i = 0;i < r;i++){
	cin >> rule[i].str >> rule[i].l >> rule[i].r;
    }
    for(long long i = 1;i <= n;i++){
	long long x = 0;
	for(long long j = 0;j < i;j++){
	    x *= PRIME;
	    x %= MOD;
	    x += str[j] - 'a' + 1;
	    x %= MOD;
	}
	long long minu = pow(PRIME, i, MOD);
	for(long long j = 0;j + i <= n;j++){
	    if(able(x, i))good.push_back(x);
		    
	    if(j + i == n)break;
	    x *= PRIME;
	    x %= MOD;
	    x += str[j + i] - 'a' + 1;
	    x -= (str[j] - 'a' + 1) * minu;
	    x %= MOD;
	    x += MOD;
	    x %= MOD;
	}
    }
    sort(good.begin(), good.end());
    good.erase(unique(good.begin(), good.end()), good.end());
    cout << good.size() << endl;
    return 0;
}