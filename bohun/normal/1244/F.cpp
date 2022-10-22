#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

int n, k;
char s[200111];

int pop(int x) {
	return (x - 1 + n) % n;
}

int nas(int x) {
	return (x + 1) % n;
}

char odw(char c) {
	if(c == 'B') return 'W';
	return 'B';
}

char res[200111];
int kloc[200111];
int t[200111];
int l[200111];
int r[200111];
			
int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	
	int o = 1;
	for(int i = 0; i < n; ++i) 
		o &= (s[i] != s[pop(i)]);
	if(o) {
		k %= 2;
		for(int i = 0; i < n; ++i) {
			if(k == 0) res[i] = s[i];
			else res[i] = odw(s[i]);
		}
		for(int i = 0; i < n; ++i)
			printf("%c", res[i]);
		return 0;
	}
	
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'B') t[i] = 0;
		else t[i] = 1;
	}
	
	int pie = n + 1;
	int last = -1;
	
	for(int i = 0; i < n; ++i) {
		if(t[i] == t[pop(i)] || t[i] == t[nas(i)]) {
			kloc[i] = 1;
			pie = min(pie, i);
			last = i;
		}
		l[i] = last;
	}
	
	int ost = -1;
	last = -1;
	
	for(int i = n - 1; 0 <= i; --i) {
		if(t[i] == t[pop(i)] || t[i] == t[nas(i)]) {
			ost = max(ost, i);
			last = i;
		}
		r[i] = last;
	}
	
	for(int i = 0; i < n; ++i) {
		if(l[i] == -1)
			l[i] = ost;
		if(r[i] == -1)
			r[i] = pie;
	}
	
	for(int i = 0; i < n; ++i) {
		if(kloc[i]) {
			res[i] = s[i];
			continue;
		}
		
		int lewo = (l[i] < i ? i - l[i] : i + n - l[i]);
		int prawo = (i < r[i] ? r[i] - i : r[i] + n - i);
	//	printf("%d %d %d %d\n", i, lewo, prawo, l[i]);
		
		if(lewo > k && prawo > k) { // blad
			if(k % 2 == 0)
				res[i] = s[i];
			else
				res[i] = odw(s[i]);
		}
		else if(lewo <= prawo) {
			res[i] = s[l[i]];
		}
		else {
			res[i] = s[r[i]];
		}
	}
	
	for(int i = 0; i < n; ++i)
		printf("%c", res[i]);
	
	
	
	
		
	
	return 0;
}