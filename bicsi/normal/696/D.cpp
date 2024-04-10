#include <bits/stdc++.h>

using namespace std;


struct Node {
	int coef;
	map<char, int> leg;
	int link;
};

Node T[256];
int nodes = 1;

string words[256];
int coef[256];

void AddString(int i) {
	int node = 1;
	for(char c : words[i]) {
		if(T[node].leg[c] == 0)
			T[node].leg[c] = ++nodes;
		node = T[node].leg[c];
	}
	T[node].coef += coef[i];
}


int Go(int node, char c) {
	while(node != 0 && !T[node].leg.count(c))
		node = T[node].link;
	if(node == 0) return 1;
	return T[node].leg[c];
}

void BuildLinks() {
	queue<int> Q;
	Q.push(1);
	T[1].link = 0;

	while(!Q.empty()) {
		int node = Q.front();
		Q.pop();

		for(auto p : T[node].leg) {
			char ch = p.first;
			int vec = p.second;

			T[vec].link = Go(T[node].link, ch);
			T[vec].coef += T[T[vec].link].coef;
			
			Q.push(vec);
		}
	}
}

typedef long long Matrix[256][256];
Matrix B, R, Aux;

void Copy(Matrix I, Matrix J) {
	for(int i = 1; i <= nodes; ++i)
		for(int j = 1; j <= nodes; ++j)
			I[i][j] = J[i][j];
}


void Mul(Matrix A, Matrix B, Matrix R) {
	for(int i = 1; i <= nodes; ++i)
		for(int j = 1; j <= nodes; ++j) {
			Aux[i][j] = -1;
			for(int k = 1; k <= nodes; ++k) {
				if(A[i][k] >= 0 && B[k][j] >= 0)
					Aux[i][j] = max(Aux[i][j], A[i][k] + B[k][j]); 
			}
		}

	Copy(R, Aux);
}

void Output(Matrix A) {
	for(int i = 1; i <= nodes; ++i, cerr << endl)
		for(int j = 1; j <= nodes; ++j)
			cerr << A[i][j] << "\t";
	cerr << endl;
}

void BuildMatrix(Matrix B) {
	for(int i = 1; i <= nodes; ++i)
		for(int j = 1; j <= nodes; ++j) {
			B[i][j] = -1;
			for(int c = 'a'; c <= 'z'; ++c)
				if(Go(j, c) == i)
					B[i][j] = T[i].coef;
		}
}

int main() {
	int n;
	long long l;

	cin >> n >> l;	
	for(int i = 1; i <= n; ++i)
		cin >> coef[i];
	for(int i = 1; i <= n; ++i)
		cin >> words[i];


	for(int i = 1; i <= n; ++i)
		AddString(i);
	BuildLinks();

	BuildMatrix(B);
	Copy(R, B);

	l--;
	while(l) {
		if(l % 2)
			Mul(R, B, R);
		Mul(B, B, B);
		l /= 2;
	}


	long long ans = -1;
	for(int i = 1; i <= nodes; ++i)
		ans = max(ans, R[i][1]);
	cout << ans << endl;

	return 0;
}