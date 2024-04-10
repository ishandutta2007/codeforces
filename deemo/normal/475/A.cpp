#include<bits/stdc++.h>

using namespace std;

string s[6];

int main(){
	s[0] = "+------------------------+";
	s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
	s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
	s[3] = "|#.......................|";
	s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
	s[5] = "+------------------------+";
	int n;	cin >> n;
	int a = 0, b = 0;
	while (n--){
		bool picked = 0;
AA:
		while (!picked && a < 6){
			if (s[a][b] == '#'){
				s[a][b] = 'O';	
				picked = 1;
			}
			a++;
		}

		if (!picked){
			b++;
			a = 0;
			goto AA;
		}
		if (a == 6)	a = 0;
	}

	for (int i = 0; i < 6; i++)
		cout << s[i] << "\n";
	return 0;
}