#include <bits/stdc++.h>

#define MAXN (100010)

int n, k;
std::map<std::pair<int, int>, bool> map;

bool ask(int x, int y){
	if(map.count({x, y})) return map[{x, y}];
	printf("1 %d %d\n", x, y);
	fflush(stdout);
	char jud[10];
	scanf("%s", jud);
	return map[{x, y}] = (jud[0] == 'T');
}

int findany(int left, int right){
	while(left < right){
		int mid = left + right >> 1;
		if(ask(mid + 1, mid)){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return left;
}

void answer(int x, int y){
	printf("2 %d %d\n", x, y);
	exit(0);
}

int tryRight(int left, int right){
	while(left < right){
		int mid = left + right >> 1;
		if(ask(mid + 1, mid)){
			return findany(mid + 1, right);
		}
		else{
			right = mid;
		}
	}
	return -1;
}

int tryLeft(int left, int right){
	while(left < right){
		int mid = left + right >> 1;
		if(ask(mid, mid + 1)){
			return findany(left, mid);
		}
		else{
			left = mid + 1;
		}
	}
	return -1;
}

int main(){
	scanf("%d%d", &n, &k);
	int fst = findany(1, n);
	
	if(fst != 1){
		if(ask(fst - 1, fst)){
			answer(fst - 1, fst);
		}
		
		if(1 < fst - 1){
			int snd = tryLeft(1, fst - 1);
			if(snd != -1){
				answer(fst, snd);
			}
	    }
	}
	
	if(fst != n){
		if(ask(fst + 1, fst)){
			answer(fst + 1, fst);
		}
		
		if(fst + 1 < n){
			int snd = tryRight(fst + 1, n);
			if(snd != -1){
				answer(fst, snd);
			}
		}
	}
		
	return 0;
}