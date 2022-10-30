#include <iostream>
#include <set>
using namespace std;

set<int> ready;
int psychos[100005];
int next   [100005];
int n;
void readInput() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> psychos[i];
	psychos[n] = 123456;
}
void prepare() {
	for (int i = 0; i < n; i++) {
		ready.insert(i);
		next[i] = i+1;
	}
}
typedef set<int>::iterator sit;
bool run() {
	set<int> toStop;
	bool didAnything = false;
	for (sit s = ready.begin(); s != ready.end(); s++){
		if (psychos[*s] == -1) { 
			toStop.insert(*s);
		} else {
			// can anybody be killed
			if (psychos[*s] < psychos[next[*s]]) {
				toStop.insert(*s);
			} else {
				// find last person that gets simul. killed
				int curix = *s;
				while (psychos[curix] > psychos[next[curix]]) {
					curix = next[curix];
				}
				int i = *s;
				while (i < curix) {
					i = next[i];
					psychos[i] = -1;
				}
				next[*s] = next[curix];

				didAnything = true;
			}
		}
	}
	for (sit s = toStop.begin(); s != toStop.end(); s++) ready.erase(*s);
	//for (int i = 0; i < n; i++) cout << psychos[i] << ",";
	//cout << endl;
	return didAnything;
}

int main() {
	readInput();
	prepare();
	int count = 0;
	while (run()) {count++;}
	cout << count << endl;
}