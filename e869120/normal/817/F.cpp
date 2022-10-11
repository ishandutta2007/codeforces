#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
const long long PACKS = 400;
long long n, q, t[100009], l[100009], r[100009]; vector<long long>C;
long long H[209000], I[1000]; bool U[1000];
void add(long long L, long long R) {
	long long I1 = L / PACKS, I2 = R / PACKS;
	for (int i = I1 + 1; i < I2; i++)I[i] = 1, U[i] = false;
	long long cnt = 0;
	if (U[I1] == true) { for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)H[i] ^= 1; U[I1] = false; }
	if (U[I2] == true) { for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)H[i] ^= 1; U[I2] = false; }
	if (I[I1] == 1) { for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)H[i] = 1; }
	if (I[I2] == 1) { for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)H[i] = 1; }
	if (I[I1] == -1) { for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)H[i] = 0; }
	if (I[I2] == -1) { for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)H[i] = 0; }
	if (I1 == I2) { for (int i = L; i < R; i++)H[i] = 1; }
	else {
		for (int i = L; i < (I1 + 1)*PACKS; i++)H[i] = 1;
		for (int i = I2*PACKS; i < R; i++)H[i] = 1;
	}
	for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)cnt += H[i];
	if (cnt == PACKS)I[I1] = 1; else if (cnt == 0)I[I1] = -1; else I[I1] = 0; cnt = 0;
	for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)cnt += H[i];
	if (cnt == PACKS)I[I2] = 1; else if (cnt == 0)I[I2] = -1; else I[I2] = 0; cnt = 0;
}
void remove(long long L, long long R) {
	long long I1 = L / PACKS, I2 = R / PACKS;
	for (int i = I1 + 1; i < I2; i++)I[i] = -1, U[i] = false;
	long long cnt = 0;
	if (U[I1] == true) { for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)H[i] ^= 1; U[I1] = false; }
	if (U[I2] == true) { for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)H[i] ^= 1; U[I2] = false; }
	if (I[I1] == 1) { for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)H[i] = 1; }
	if (I[I2] == 1) { for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)H[i] = 1; }
	if (I[I1] == -1) { for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)H[i] = 0; }
	if (I[I2] == -1) { for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)H[i] = 0; }
	if (I1 == I2) { for (int i = L; i < R; i++)H[i] = 0; }
	else {
		for (int i = L; i < (I1 + 1)*PACKS; i++)H[i] = 0;
		for (int i = I2*PACKS; i < R; i++)H[i] = 0;
	}
	for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)cnt += H[i];
	if (cnt == PACKS)I[I1] = 1; else if (cnt == 0)I[I1] = -1; else I[I1] = 0; cnt = 0;
	for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)cnt += H[i];
	if (cnt == PACKS)I[I2] = 1; else if (cnt == 0)I[I2] = -1; else I[I2] = 0; cnt = 0;
}
void invert(long long L, long long R) {
	long long I1 = L / PACKS, I2 = R / PACKS;
	for (int i = I1 + 1; i < I2; i++) {
		if (I[i] == 1) { I[i] = -1; U[i] ^= true; }
		else if (I[i] == -1) { I[i] = 1; U[i] ^= true; }
		else U[i] ^= true;
	}
	long long cnt = 0;
	if (U[I1] == true) { for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)H[i] ^= 1; U[I1] = false; }
	if (U[I2] == true) { for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)H[i] ^= 1; U[I2] = false; }
	if (I[I1] == 1) { for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)H[i] = 1; }
	if (I[I2] == 1) { for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)H[i] = 1; }
	if (I[I1] == -1) { for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)H[i] = 0; }
	if (I[I2] == -1) { for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)H[i] = 0; }
	if (I1 == I2) { for (int i = L; i < R; i++)H[i] ^= 1; }
	else {
		for (int i = L; i < (I1 + 1)*PACKS; i++)H[i] ^= 1;
		for (int i = I2*PACKS; i < R; i++)H[i] ^= 1;
	}
	for (int i = I1*PACKS; i < (I1 + 1)*PACKS; i++)cnt += H[i];
	if (cnt == PACKS)I[I1] = 1; else if (cnt == 0)I[I1] = -1; else I[I1] = 0; cnt = 0;
	for (int i = I2*PACKS; i < (I2 + 1)*PACKS; i++)cnt += H[i];
	if (cnt == PACKS)I[I2] = 1; else if (cnt == 0)I[I2] = -1; else I[I2] = 0; cnt = 0;
}
long long query() {
	for (int i = 0; i < (n / PACKS) + 1; i++) {
		if (I[i] != 1) {
			if (I[i] == -1)return i*PACKS;
			for (int j = i*PACKS; j < (i + 1)*PACKS; j++) {
				if (((H[j]) ^ (int)(U[i])) == 0)return j;
			}
		}
	}
	return -1;
}
int main() {
	cin >> q;
	for (int i = 0; i < q; i++) { scanf("%lld%lld%lld", &t[i], &l[i], &r[i]); r[i]++; C.push_back(l[i]); C.push_back(r[i]); }
	C.push_back(1); sort(C.begin(), C.end()); C.erase(unique(C.begin(), C.end()), C.end()); n = C.size() + 1;
	for (int i = 0; i < q; i++) {
		int pos1 = lower_bound(C.begin(), C.end(), l[i]) - C.begin(); l[i] = pos1;
		int pos2 = lower_bound(C.begin(), C.end(), r[i]) - C.begin(); r[i] = pos2;
	}
	for (int i = 0; i < q; i++) {
		if (t[i] == 1)add(l[i], r[i]);
		if (t[i] == 2)remove(l[i], r[i]);
		if (t[i] == 3)invert(l[i], r[i]);
		printf("%lld\n", C[query()]);
	}
	return 0;
}