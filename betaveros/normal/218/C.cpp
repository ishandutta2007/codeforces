#include <cstdio>
using namespace std;
// codeforces submission -- round 0x86 -- betaveros

// 1 ~ 1000: x
// 1001 ~ 2000: y

bool appeared[2001];
bool rootAppeared[2001];
int parent[2001];

void reset(){
	for (int i = 0; i < 2001; i++){
		appeared[i] = false;
		rootAppeared[i] = false;
	}
}

int root(int a){
	if (parent[a] == a) return a;

	int r = root(parent[a]);
	parent[a] = r;
	return r;
}

void init(int a){
	if (!appeared[a]){
		appeared[a] = true;
		parent[a] = a;
	}
}

void join(int a, int b){
	init(a);
	init(b);
	parent[root(a)] = root(b);
}

void readInput(){
	reset();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		join(x, 1000 + y);
	}
}

int setCount(){
	int roots = 0;
	for (int i = 1; i <= 2000; i++){
		if (appeared[i]){
			int r = root(i);
			if (!rootAppeared[r]){
				rootAppeared[r] = true;
				roots++;
			}
		}
	}
	return roots;
}

int main(){
	readInput();
	printf("%d", setCount() - 1);
}