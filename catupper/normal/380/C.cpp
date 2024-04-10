#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
vector<int> opens, close;

struct T{
	int opn, cls, cmp;
	T(){
		opn = cls = cmp = 0;
	}
	T(int a, int b, int c){
		opn = a;
		cls = b;
		cmp = c;
	}
};

T cmb(T a, T b){
	T res;
	res.cmp = a.cmp + b.cmp;
	int t = min(a.opn, b.cls);
	res.cmp += t * 2;
	res.opn = a.opn + b.opn - t;
	res.cls = a.cls + b.cls - t;
	return res;
}

char str[1 << 20];
T zero;
T seg[1 << 21];

T solve(int l, int r, int bottom = 0, int top = 1 << 20, int pos = 1){
	if(r <= bottom || top <= l)return zero;
	if(l <= bottom && top <= r)return seg[pos];
	int mid = (bottom + top) / 2;
	return cmb(solve(l, r, bottom, mid, pos * 2),
		   solve(l, r, mid, top, pos * 2 + 1));
}

int main(){
	int q, l, r;
	gets(str);
	int sl = strlen(str);
	for(int i = 0;i < sl;i++){
        	if(str[i] == '(')seg[(1 << 20) + i].opn = 1;
		else seg[(1 << 20) + i].cls = 1;
	}
	for(int i = (1 << 20) - 1;i >= 1;i--){
		seg[i] = cmb(seg[i * 2], seg[i * 2 + 1]);
	}
	cin >> q;	
	while(q--){
		cin >> l >> r;
		cout << solve(l - 1, r).cmp << endl;
	}
	return 0;
}