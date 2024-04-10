#include<iostream>
#include<algorithm>

using namespace std;
#define MOD 1000000007
typedef long long Int;


struct M{
	Int val[1 << 7][1 << 7];
	int s;
	M(int x = 7){
		s = x;
		for(Int i = 0;i < (1 << s);i++)
			for(Int j = 0;j < (1 << s);j++)
				val[i][j] = (i==j);
	}
};

M E;

M mult(M &a, M b){
	M res = M(a.s);
	int s = a.s;
	for(Int i = 0;i < (1 << s);i++){
		for(Int j = 0;j < (1 << s);j++){
			res.val[i][j] = 0;
			for(Int k = 0;k < (1 << s);k++){
				res.val[i][j] += a.val[i][k] * b.val[k][j];
				res.val[i][j] %= MOD;
			}
		}
	}
	return res;
}

M pow(M &a, Int x){
	if(x == 0)return M(a.s);
	M res = pow(a, x/2);
	res = mult(res, res);
	if(x%2)res = mult(res, a);
	return res;
}

M solve(Int x){
	Int w;
	cin >> w;
	M res = M(x);
	for(int i = 0;i < (1 << x);i++)res.val[i][i] = 0;
	for(Int i = 0;i < (1 << x);i++){
		for(Int j = 0;j < (1 << x);j++){
			for(Int k = 0;k < (1 << (x-1));k++){
				if((i | j | k | (k << 1)) == (1 << x) - 1)res.val[i][j]++;		
			}
		}
	}
	return pow(res, w);
}

int main(){
	M res = E;
		
	for(Int i = 1;i <= 7;i++){
		res = mult(res, solve(i));
	}
	cout << res.val[0][0] << endl;
	return 0;
}