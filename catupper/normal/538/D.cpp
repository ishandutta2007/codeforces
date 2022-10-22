#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;
#define INF (1LL<<60)
#define MOD 1000000007

char pos[108][108];
char ans[108][108];
char tmp[108][108];
int n;


bool possible(int di, int dj){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			int ti = i + di, tj = j + dj;
			if(ti < 0 || ti >= n || tj < 0 || tj >= n)continue;
			if(pos[i][j] != 'o')continue;
			if(pos[ti][tj] == '.')return false;
		}
	}
	return true;
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> pos[i][j];
			tmp[i][j] = '.';
		}
	}
	for(int di = -n+1;di < n;di++){
		for(int dj = -n+1;dj < n;dj++){
			if(di == 0 && dj == 0){
				ans[di + n - 1][dj + n - 1] = 'o';
				continue;
			}
			if(possible(di, dj))ans[di + n - 1][dj + n - 1] = 'x';
			else ans[di + n - 1][dj + n - 1] = '.';
		}
	}
	bool ok = true;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(pos[i][j] == 'o'){
				for(int di = -n+1;di < n;di++){
					for(int dj = -n+1;dj < n;dj++){
						if(ans[di + n - 1][dj + n - 1] == 'x'){
							int ti = i + di, tj = j + dj;
							if(ti < 0 || ti >= n || tj < 0 || tj >= n)continue;
							tmp[ti][tj] = 'x';
						}
					}
				}
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(pos[i][j] == 'o')
				tmp[i][j] = 'o';
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(tmp[i][j] != pos[i][j]){
				ok = false;
			}
		}                   
	}
	if(!ok){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 0;i < 2*n-1;i++){
		for(int j = 0;j < 2*n-1;j++){
			cout << ans[i][j];
		}                     cout << endl;
	}
	return 0;
	
}