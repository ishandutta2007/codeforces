#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int type;
string s;

int main() {
	scanf("%d", &type);
	static char buffer[100];
	scanf("%s", buffer);
	s = buffer;
	string hour, minute;
	hour = s.substr(0, 2);
	minute = s.substr(3, 2);
	if (type == 12) {
		if (hour[0] > '1') {
			if (hour[1] == '0') {
				hour[0] = '1';
			} else {
				hour[0] = '0';
			}
		}
		if (hour[0] == '0' && hour[1] == '0') {
			hour[1] = '1';
		}
		if (hour[0] == '1' && (hour[1] > '2')) {
			hour[1] = '1';
		}
	} else {
		if (hour[0] > '2') {
			hour[0] = '0';
		}
		if (hour[0] == '2' && hour[1] > '3') {
			hour[1] = '0';
		}
	}
	if (minute[0] > '5') {
		minute[0] = '0';
	}
	hour[2] = 0;
	minute[2] = 0;
	cout << hour << ":" << minute << endl;
	return 0;
}