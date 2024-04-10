#include<iostream>
#include<algorithm>

using namespace std;

struct M{
	int val[60];
	M(int x = 0){
		for(int i = 0;i < 60;i++){
			if(x == 0)val[i] = 0;
			else if(i % x)val[i] = 1;
			else val[i] = 2;
		}
	}
};

M seg[1 << 18];

M mult(M x, M y){
	M res;
	for(int i = 0;i < 60;i++){
		res.val[i] = x.val[i] + (y.val[(x.val[i] + i) % 60]);
	}
	return res;
};

void setval(int pos, M x){
	pos += 1 << 17;
	seg[pos] = x;
	while(pos/=2){
		seg[pos] = mult(seg[pos*2], seg[pos*2+1]);
	}
}
M ZERO;
M solve(int l, int r, int bottom = 0, int top = 1 << 17, int pos = 1){
	if(r <= bottom || top <= l)return ZERO;
	if(l <= bottom && top <= r)return seg[pos];
	int mid = (bottom + top) / 2;
	return mult(solve(l, r, bottom, mid, pos * 2),
				solve(l, r, mid, top, pos * 2 + 1));
}

int main(){
	int n, x, y, q, a;
	char c;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a;
		setval(i, M(a));
	}
	cin >> q;
	while(q--){
		cin >> c >> x >> y;
		if(c == 'C'){
			x--;
			setval(x, M(y));
		}
		if(c == 'A'){
			x--, y--;
			M tmp = solve(x, y);
			cout << tmp.val[0] << endl;
		}
	}
	return 0;
}