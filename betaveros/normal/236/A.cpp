#include <cstdio>
using namespace std;


int distincts(char* s){
	bool h[27];
	for (int i = 0; i < 27; i++) h[i] = false;
	int x = 0;
	while (s[x] != '\0'){
		h[ (s[x] - 'a') ] = true;
		x++;
	}
	int cnt = 0;
	for (int i = 0; i < 27; i++) if (h[i]) cnt++;
	return cnt;
}

int main(){
	char read[110];
	scanf("%s", read);
	if (distincts(read) % 2 != 0){
		printf("IGNORE HIM!\n");
	} else {
		printf("CHAT WITH HER!\n");
	}
}