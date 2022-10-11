#include <iostream>
#include <string>
using namespace std;

string S[7] = {
	"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"
};

string S1, S2; int id1, id2;

int main() {
	cin >> S1; for (int i = 0; i < 7; i++) { if (S[i] == S1) id1 = i; }
	cin >> S2; for (int i = 0; i < 7; i++) { if (S[i] == S2) id2 = i; }

	int Z = (id2 - id1 + 7) % 7;
	if (Z == 0 || Z == 2 || Z == 3) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}