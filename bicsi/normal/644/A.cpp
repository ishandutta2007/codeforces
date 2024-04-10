#include <bits/stdc++.h>

using namespace std;

int Bad[2], I[100000], J[100000];
queue<int> Q;

int Seats[500][500];

int dx[] = {0,1 , 0, -1},
    dy[] = {1, 0, -1, 0};

int main() {

    int n, a, b;
    cin >> n >> a >> b;

    Bad[0] = 1;
    Bad[1] = 2;

    auto now = Bad[0];
    Bad[0] += 2;
    Seats[1][1] = now;
    I[now] = J[now] = 1;
    Q.push(now);

    while(!Q.empty()) {
        auto top = Q.front();
        Q.pop();

        int i = I[top],
            j = J[top];



        for(int d=0; d<4; d++) {
            int newi = i + dx[d];
            int newj = j + dy[d];

            if(newi <= 0 || newj <= 0 || newi > a || newj > b || Seats[newi][newj]) continue;

            if(Bad[top % 2] > n) continue;


            I[Bad[top % 2]] = newi;
            J[Bad[top % 2]] = newj;
            Seats[newi][newj] = Bad[top % 2];
            Q.push(Bad[top % 2]);

            Bad[top % 2] += 2;
        }
    }

    if(I[n] == 0 || (n >= 2 && I[n-1] == 0)) {
        cout << -1;
    } else {
        for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            cout << Seats[i][j] << " ";
        }
        cout << '\n';
        }
    }



    return 0;
}