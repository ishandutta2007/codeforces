#include <stdio.h>
#include <vector>
using namespace std;
char d[100050];
vector <char> S;
int main() {
	int cnt_l = 0, cnt_r = 0, cnt_s = 0, las = -1, i;
	scanf("%s", &d);
	for(i = 0; d[i] != 0; i++) {
		if(d[i] == '(') cnt_l++;
		else if(d[i] == ')') cnt_r++;
		else {
			cnt_s++;
			las = i;
		}
	}
	if(cnt_l < cnt_r+cnt_s) {
		printf("-1");
		return 0;
	}
	int tmp_cnt = 0;
	for(i = 0; d[i] != 0; i++) {
		if(d[i] == '(') tmp_cnt++;
		else if(d[i] == ')') tmp_cnt--;
		else {
			if(i == las) tmp_cnt -= cnt_l-cnt_r-cnt_s+1;
			else tmp_cnt--;
		}
		if(tmp_cnt < 0) break;
	}
	if(d[i] != 0) printf("-1");
	else {
		for(i = 1; i < cnt_s; i++) printf("1\n");
		printf("%d", cnt_l-cnt_r-cnt_s+1);
	}
	return 0;
}