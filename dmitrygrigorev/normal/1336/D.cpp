#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define aint(a) a.begin(), a.end()

using namespace std;

int n;

int three(int x) {
	return x*(x-1)*(x-2)/6;
}

vector<int> arr;
void ask(int x, int &a, int &b) {
	cout << "+ " << x+1 << endl;
	arr[x]++;
	a = 0, b = 0;
	cin >> a >> b;

}

void give(int &a, int &b) {

	cin >> a >> b;

}

void gen() {
	/*
	cout << "ARR = ";
	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % (n+1);
		cout << arr[i] << " ";
	}
	cout << endl;
	*/
}

main(){
#ifdef LOCAL
	//freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	arr.assign(n, 0);

	gen();
	vector<int> tarr=arr;

	vector<int> val(n, -1);

	int a, b;
	give(a, b);
	int sb = b;

	int zero = -1;
	vector<pair<int, int> > answers;

	for (int i = 0; i < n-1; ++i) {
		int c, d;
		ask(i, c, d);
		answers.push_back({c, d});

		if (c != a) {
			int was = 2;
			while (c - a != three(was+1) - three(was)) {
				was++;
			}

			val[i] = was;
		}

		else {
			if (zero == 0) val[i] = 1;
			else if (zero == 1) val[i] = 0;
		}

		//cout << b << " " << val[i]+1 << " " << val[i-1]+1 << " " << val[i-2]+1 << " " << d << endl;

		if (i == 2) {

			int cb = b, cd = d;
			a = c, b = d;

			ask(0, c, d);
			if (c != a) {
				int was = 2;
				while (c - a != three(was+1) - three(was)) {
					was++;
				}

				val[0] = was-1;
			}

			else {
				val[0] = 0;
			}

			int dwas = answers[0].second - sb;
			int dtut = d - b - dwas - 1;

			val[1] = dtut - val[2];
			a = c, b = d;
///////////////////////////
			int Q = 0;
			if (i >= 2) Q = (val[i-1]+1) * (val[i-2] + 1);

			if (i <= 1) zero=-1;
			else if (cb+Q == cd) {
				zero = 1;
			}
			else zero = 0;
			//cout << cb << " " << Q << " " << cd << endl;
		}

		else {

			int Q = 0;
			if (i >= 2) Q = (val[i-1]+1) * (val[i-2] + 1);

			if (i <= 1) zero=-1;
			else if (b+Q == d) {
				zero = 1;
			}
			else zero = 0;

			if (i == 1 && b == d) zero = 1;
			else if (i==1) zero = 0;

			a = c, b = d;

		}

	}

	for (int i = 0; i + 3 < n; ++i) {
		b -= (val[i]+1+(i==0)) * (val[i+1] + 1) * (val[i+2] + 1);
	}

	b /= ((val[n-2]+1) * (val[n-3]+1));


	assert(val[2] != -1);
	val.back() = b;
	cout << "! ";
	for (int i = 0; i < n; ++i) cout << val[i] << " ";
	cout << endl;

}