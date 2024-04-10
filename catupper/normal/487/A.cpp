#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
#define INF (1 << 30)
int turn(int hp, int atk, int def){
	int a = max(atk - def, 0);
	if(a == 0)return INF;
	else return (hp / a) + (hp % a != 0);
}

int main(){
    int hpy, atky, defy, hpm, atkm, defm;
	int h, a, d;
	int th, ta, td;
	int res = INF;
	cin >> hpy >> atky >> defy;
	cin >> hpm >> atkm >> defm;
	cin >> h >> a >> d;

	for(int atk = 0;atk <= 200;atk++){
		for(int def = 0;def <= 100;def++){
			ta = atky + atk;
			td = defy + def;
			int bottom = hpy-1, top = INF / 2;
			if(turn(hpm, ta, defm) == INF)continue;
			while(top - bottom > 1){
				int mid = (top + bottom) / 2;
				if(turn(hpm, ta, defm) < turn(mid, atkm, td))top = mid;
				else bottom = mid;
			}
			th = top;
			int hp = th - hpy;
			res = min(res, h * hp + a * atk + d * def);
		}
	} 

	cout << res << endl;	
	return 0;
}