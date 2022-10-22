#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef pair<int, int> P;
set<P> rng;
char c[324000];
int n, m, res;
#define INF (1 << 30)
void add(int x){
	set<P>::iterator it = rng.lower_bound(P(x, x)), jt;
	if(c[x] == '.')return;
	c[x] = '.';
	if(x > 0 && c[x-1] == '.' && c[x+1] == '.'){
		it--;
		jt = it;jt++;
		P tmp = P(it->first, (jt)->second);
		it++;
		res -= (x-1) - tmp.first;
		res -= tmp.second - (x+1);
		res += tmp.second - tmp.first;
		rng.erase(it--);
		rng.erase(it);
		rng.insert(tmp);
		return;
	}
	if(x > 0 && c[x-1] == '.'){
		it--;
		P tmp = P(it->first, x);	
		res -= (x-1) - tmp.first;
		res += tmp.second - tmp.first;
		rng.erase(it);
		rng.insert(tmp);
		return;
	}
	if(c[x+1] == '.'){
		P tmp = P(x, it->second);
		res -= tmp.second - (x+1);
		res += tmp.second - tmp.first;
		rng.erase(it);
		rng.insert(tmp);
		return;
	}
	rng.insert(P(x, x));
}

void cut(int x){
	set<P> :: iterator it = rng.lower_bound(P(x, INF));
	if(c[x] != '.')return;
	c[x] = 'a';
	it--;
	if(it->first == x && it->second == x){
		rng.erase(it);
		return;
	}
	if(it->first == x){
		P tmp = P(x+1, it->second);
		rng.erase(it);
		rng.insert(tmp);
		res--;
		return;
	}
	if(it->second == x){
		P tmp = P(it->first, x-1);
		rng.erase(it);
		rng.insert(tmp);
		res--;
		return;
	}
	P tmp1 = P(x+1, it->second);
	P tmp2 = P(it->first, x-1);
	res -= it->second - it->first;
	res += tmp1.second - tmp1.first;
	res += tmp2.second - tmp2.first;
	rng.erase(it);
	rng.insert(tmp1);
	rng.insert(tmp2);
	
}
       
int from, p;
char cc;

int main(){
	cin >> n >> m;
	from = -1;
	for(int i = 0;i < n;i++){
		cin >> c[i];
		if(c[i] == '.'){
			if(from == -1)from = i;
		}
		else{
			if(from != -1){
				rng.insert(P(from, i - 1));
				res += i - 1 - from;
				from = -1;
			}
		}
	}
	if(from != -1){
		rng.insert(P(from, n - 1));
		res += n - 1 - from;
	}
	for(int i = 0;i < m;i++){
		cin >> p >> cc;
		p--;
		if(cc == '.')add(p);
		else cut(p);
		cout << res << endl;
	}
	return 0;
}