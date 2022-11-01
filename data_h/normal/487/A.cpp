#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX = 200;
const int INF = 1000000;

struct Ability {
	int ATK, HP, DEF;
	Ability() {}
	void read() {
		scanf("%d %d %d", &HP, &ATK, &DEF);
	}
};

Ability yang, monster;

int solve(Ability a, Ability b) {
	if (a.ATK - b.DEF <= 0) {
		return INF;
	}
	int result = 0;
	while(b.HP > 0) {
		result += max(0, b.ATK - a.DEF);
		b.HP -= max(0, a.ATK - b.DEF);
	}
	return result;
}

int main() {
	yang.read();
	monster.read();
	int h, a, d;
	scanf("%d %d %d", &h, &a, &d);
	int answer = INF;
	for(int DEF = 0; DEF <= MAX; DEF++) {
		for(int ATK = 0; ATK <= MAX; ATK++) {
			Ability temp = yang;
			temp.ATK += ATK;
			temp.DEF += DEF;
			int lowest = solve(temp, monster);
			answer = min(answer, max(0, lowest - yang.HP + 1) * h + DEF * d + ATK * a);
		}
	}
	printf("%d\n", answer);
	return 0;
}