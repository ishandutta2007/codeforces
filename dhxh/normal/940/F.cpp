#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];

struct ex {
	int l, r, t, n;
};

struct opt {
	int p, x, y;
};

vector <ex> que;
vector <opt> op;

int ans[maxn];

int size;

map <int, int> ss;
int scnt;
int s[2 * maxn];
int cnt[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(ex x, ex y){
	if(x.l / size != y.l / size){
		return x.l < y.l;
	}else{
		if(x.r / size != y.r / size){
			return x.r < y.r;
		}else{
			return x.t < y.t;
		}
	}
}

int main(){
	int i, j;
	int o;
	int x, y;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		if(!ss[a[i]]){
			ss[a[i]] = ++scnt;
		}
		a[i] = ss[a[i]];
	}
	
	for(j=1;j<=m;j++){
		o = read();
		x = read();
		y = read();
		
		if(o == 1){
			que.push_back((ex){x, y, (int)op.size(), (int)(que.size() + 1)});
		}else{
			if(!ss[y]){
				ss[y] = ++scnt;
			}
			y = ss[y];
			op.push_back((opt){x, y});
		}
	}
	
	for(i=0;i<op.size();i++){
		op[i].y = a[op[i].p];
		a[op[i].p] = op[i].x;
	}
	
	for(i=op.size()-1;i>=0;i--){
		a[op[i].p] = op[i].y;
	}
	
	size = pow(n, 2.0 / 3.0);
	
	sort(que.begin(), que.end(), cmp);
	
	int l = 1, r = 1, t = 0;
	
	s[a[1]] = 1;
	cnt[1] = 1;
	
	for(ex tmp : que){
		while(l > tmp.l){
			l--;
			cnt[s[a[l]]]--;
			s[a[l]]++;
			cnt[s[a[l]]]++;
		}
		
		while(r < tmp.r){
			r++;
			cnt[s[a[r]]]--;
			s[a[r]]++;
			cnt[s[a[r]]]++;
		}
		
		while(l < tmp.l){
			cnt[s[a[l]]]--;
			s[a[l]]--;
			cnt[s[a[l]]]++;
			l++;
		}
		
		while(r > tmp.r){
			cnt[s[a[r]]]--;
			s[a[r]]--;
			cnt[s[a[r]]]++;
			r--;
		}
		
		while(t < tmp.t){
			if(l <= op[t].p and op[t].p <= r){
				cnt[s[a[op[t].p]]]--;
				s[a[op[t].p]]--;
				cnt[s[a[op[t].p]]]++;
			}
			a[op[t].p] = op[t].x;
			if(l <= op[t].p and op[t].p <= r){
				cnt[s[a[op[t].p]]]--;
				s[a[op[t].p]]++;
				cnt[s[a[op[t].p]]]++;
			}
			t++;
		}
		
		while(t > tmp.t){
			t--;
			if(l <= op[t].p and op[t].p <= r){
				cnt[s[a[op[t].p]]]--;
				s[a[op[t].p]]--;
				cnt[s[a[op[t].p]]]++;
			}
			a[op[t].p] = op[t].y;
			if(l <= op[t].p and op[t].p <= r){
				cnt[s[a[op[t].p]]]--;
				s[a[op[t].p]]++;
				cnt[s[a[op[t].p]]]++;
			}
		}
		
		for(i=1;i<=1e5;i++){
			if(!cnt[i]){
				ans[tmp.n] = i;
				break;
			}
		}
	}
	
	for(i=1;i<=que.size();i++){
		printf("%d\n", ans[i]);
	}
	
	return 0;
}