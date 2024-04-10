#include <iostream>
#include <algorithm>

using namespace std;
bool f =false;
int color[500], a[500][500];

int n;
void NO() {
        cout << "NO";
        cin >> n;
        exit(0);
}
void dfs(int i, int pr){
        color[i] = 1;
        for (int j = 1; j <= n; j++){
                if (a[i][j] == 1 && pr != j) {
                        if (color[j] == 1) {
                                if (f == true) {
                                        NO();
                                } else {
                                        f = true;
                                }
                        } else {
							if (color[j] == 0)
                                dfs(j, i);
                        }
                }
        }
		color[i] = 2;
}
int main(){
		//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        int i, x, m, y, b[50];
        cin >> n >> m;
        for (i = 0; i < m; i++){
                cin >> x >> y;
                a[x][y] = 1;
                a[y][x] = 1;
        }
        dfs(1, -1);
        for (i = 1; i <= n; i++){
                if (color[i] == 0) {
                        NO();
                }
        }

        if (f == false) {
                NO();
        }
        cout << "FHTAGN!";
        cin >> n;
}