#include <bits/stdc++.h>
#define data suka
#define ll long long
#define ull unsigned long long
#define db long double

using namespace std;
const int K = 2048;
const int LEN = K/64;
struct My_bitset{
	ull arr[LEN];
	int cnt;

	My_bitset(){
		for (int i=0; i < LEN; ++i) arr[i] = 0;
		cnt=0;
	}

	int count(){
		return cnt;
	}

	bool is_subset(My_bitset &b){
		for (int i=0; i < LEN; ++i){
			ull X = b.arr[i] & arr[i];
			ull T = X^b.arr[i];
			if (T!=0) return false;
		}
		return true;
	}

	void change(int l, int r){
		for (int i=0; i < LEN; ++i){
			int L = i*64, R = (i+1)*64 - 1;
			L = max(L, l), R = min(R, r);
			if (L > R) continue;
			cnt -= __builtin_popcountll(arr[i]);
			ull a = L%64, b = R%64;
			if (b==63) b = ULLONG_MAX;
			else b = (1LL<<(b+1))-1;
			a = (1LL<<a)-1;
			arr[i] ^= (b-a);
			cnt += __builtin_popcountll(arr[i]);
		}
	}

	int special(My_bitset &b){
		for (int i=0; i < LEN; ++i){
			ull X = b.arr[i] & arr[i];
			ull T = X^b.arr[i];
			if (T==0) continue;
			for (int j=0; j < 64; ++j){
				ull ba = (1ULL<<j)&T;
				if (ba==0) continue;
				return 64*i+j;
			}
		}
	}
	
};

vector<My_bitset> bitsets;

set<int> bad_bitsets;

struct cmp {
    bool operator() (const int& a, const int& b) const {
        int A = bitsets[a].count(), B = bitsets[b].count();
	    if (A != B) return (A<B);
	    return (a<b);
    }
};

set<int, cmp> ms;

void change_triplet(int a, int b, int c, bool is_removal){
	if (a==-1 && c==-1) return;
	if (c==-1){
		c=b;
		b=a;
		a=-1;
	}
	if (a==-1){
		bool resb_c = bitsets[c].is_subset(bitsets[b]);
		if (is_removal){
			if (!resb_c) bad_bitsets.erase(bad_bitsets.find(b));
		}
		else{
			if (!resb_c) bad_bitsets.insert(b);
		}
		return;
	}
	bool resa_b = bitsets[b].is_subset(bitsets[a]);
	bool resb_c = bitsets[c].is_subset(bitsets[b]);
	bool resa_c = bitsets[c].is_subset(bitsets[a]);
	if (is_removal){
		if (!resa_b) bad_bitsets.erase(bad_bitsets.find(a));
		if (!resb_c) bad_bitsets.erase(bad_bitsets.find(b));
		if (!resa_c) bad_bitsets.insert(a);
	}
	else{
		if (!resa_c) bad_bitsets.erase(bad_bitsets.find(a));
		if (!resa_b) bad_bitsets.insert(a);
		if (!resb_c) bad_bitsets.insert(b);
	}
}

void print_answer(int x){
	auto it = ms.find(x);
	it++;
	int y = *it;
	int a = bitsets[x].special(bitsets[y]), b = bitsets[y].special(bitsets[x]);
	cout << min(x, y)+1 << " " << min(a, b)+1 << " " << max(x, y)+1 << " " << max(a, b)+1 << "\n";
}

main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	bitsets.assign(n, {});
	for (int i=0; i < n; ++i) ms.insert(i);
	for (int i=0; i < q; ++i){
		int a, l, r;
		cin >> a >> l >> r;
		a--, l--, r--;
		auto it = ms.find(a);
		int first_t = -1, second_t = a, third_t = -1;
		if (it != ms.begin()){
			it--;
			first_t = (*it);
			it++;
		}
		it++;
		if (it != ms.end()){
			third_t = (*it);
		}
		change_triplet(first_t, second_t, third_t, true);
		//cout << first_t << " " << second_t << " " << third_t << endl;
		ms.erase(ms.find(a));
		bitsets[a].change(l, r);
		ms.insert(a);
		it = ms.find(a);
		first_t = -1, second_t = a, third_t = -1;
		if (it != ms.begin()){
			it--;
			first_t = (*it);
			it++;
		}
		it++;
		if (it != ms.end()){
			third_t = (*it);
		}
		change_triplet(first_t, second_t, third_t, false);
		if (bad_bitsets.size() == 0){
			cout << "-1\n";
			continue;
		}
		int bad = *bad_bitsets.begin();
		print_answer(bad);
	}
}