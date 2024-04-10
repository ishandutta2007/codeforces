#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
char s[100][100];
bool in(int x, int y){
	if(0 <= x && x < 4 && 0 <= y && y < 4 && s[x][y] == 'x')
		return 1;
	else
		return 0;
}
bool solve1(int x, int y, int dx, int dy){
	if(in(x, y) && in(x + dx, y + dy) && in(x + dx * 2, y + dy * 2))
		return 1;
	else
		return 0;
}
bool solve(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(solve1(i ,j, 0, 1)) return 1;
			if(solve1(i, j, 1, 0)) return 1;
			if(solve1(i, j, 1, 1)) return 1;
			if(solve1(i, j, 1, -1)) return 1;
		}
	}
	return 0;
}
bool check(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(s[i][j] == '.'){
				s[i][j] = 'x';
				if(solve())
					return 1;
				s[i][j] = '.';
			}
		}
	}
	return 0;
}
int main(){
	for(int i = 0 ; i < 4 ;i++)
		scanf("%s", s[i]);
	if(check())
		puts("YES");
	else
		puts("NO");
	return 0;
}