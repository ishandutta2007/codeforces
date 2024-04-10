#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

long long N;
char a[200001];
char b[200001];
int b_k[26][200001];	//b_k[l][i] = numero di lettere 'l' in b prima della posizione i
long long b_s[26][200001];	//b_s[l][i] = somma delle posizioni delle lettere 'l' prima della posizione i
double solution;

void solve() {
	for(int i = 1; i <= N; ++i) {
		for(int l = 0; l < 26; ++l) {
			if(b[i - 1] - 'A' == l) {
				b_s[l][i] = b_s[l][i - 1] + i - 1;
				b_k[l][i] = b_k[l][i - 1] + 1;
			}
			else {
				b_s[l][i] = b_s[l][i - 1];
				b_k[l][i] = b_k[l][i - 1];
			}
		}
	}
	
	for(int i = 0; i < N; ++i) {
		int l = a[i] - 'A';
		solution += (i + 1) * (N * (b_k[l][int(N)] - b_k[l][i]) - (b_s[l][int(N)] - b_s[l][i]))
			+ (N - i) * (b_s[l][i] + b_k[l][i]);
	}
	
	solution /= N * (N + 1) * (2 * N + 1) / 6; //somma di quadrati degli interi da 1 a N = N(N+1)(2N+1)/6
}

void read() {
	std::cin >> N;
	std::cin >> a;
	std::cin >> b;
}

void write() {
	std::cout << std::fixed << std::setprecision(10) << solution;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	read();
	solve();
	write();
	return 0;
}