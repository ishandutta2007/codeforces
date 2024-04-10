#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N;

	int psum = 0, osum = 0;

	cin >> N;
	if(N%4 == 0 || N%4 == 3)
		cout << 0 << endl;
	else
		cout << 1 << endl;
	vector<int> pieces;
	vector<int> oth;
	int offset = N%4;
	if(N%4 != 0) {
		pieces.push_back(1);
		psum += 1;
	}
	if(N%4 == 2) {
		oth.push_back(2);
		osum += 1;
	}
	if(N%4 == 3) {
		pieces.push_back(2);
		oth.push_back(3);
		psum += 2;
		osum += 3;
	}

	int Nfl = (N/4)*4;
	for(int i=0;i<N/4;++i) {
		pieces.push_back(i*2+1+offset);
		psum += pieces.back();
		pieces.push_back(N-i*2);
		psum += pieces.back();
		oth.push_back(i*2+2+offset);
		osum += oth.back();
		oth.push_back(N-i*2-1);
		osum += oth.back();
	}


	cout << pieces.size() << " ";
	for( int ii : pieces ) {
		cout << ii << " ";
	}
	cout << endl;

	//cerr << "::" << psum << " " << osum << endl;
	

	return 0;
}