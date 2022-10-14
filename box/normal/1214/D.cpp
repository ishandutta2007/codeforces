#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
 
bool val[1000006];
int pred[1000006];
bool vist[1000006];
 
int n, m;
 
void succ(const int& orig, int& a, int& b) {
    int row = orig/m, col = orig%m;
    if(row == n-1 && col == m-1) {
        a = -1; b = -1;
    } else if(col == m-1) {
        a = (row+1)*m+col; b = -1;
    } else if(row == n-1) {
        a = (row)*m+col+1; b = -1;
    } else {
        a = (row)*m+col+1; b = (row+1)*m+col;
    }
}
 
bool pathexistanderasepath() {
    memset(pred, 255, sizeof pred); memset(vist, 0, sizeof vist);
    queue<int> bfq;
    bfq.push(0); vist[0] = true; pred[0] = -1;
    while(!bfq.empty()) {
        int at = bfq.front(); bfq.pop();
        int s1, s2; succ(at, s1, s2);
        if(s1 == -1) break;
        if(val[s1] && !vist[s1]) {
            bfq.push(s1);
            vist[s1] = true;
            pred[s1] = at;
        }
        if(s2 != -1 && val[s2] && !vist[s2]) {
            bfq.push(s2);
            vist[s2] = true;
            pred[s2] = at;
        }
    }
    if(vist[n*m-1] == false) return false;
    int at = n*m-1;
    while(at != -1) {
        if(at != 0 && at != n*m-1) val[at] = 0;
        at = pred[at];
    }
    return true;
}
 
int main() {
    cin >> n >> m;
    int id = 0;
    for(int i=0; i<n*m; i++) {
        char c; cin >> c;
        if(c == '.') val[id] = 1;
        else if(c == '#') val[id] = 0;
        id++;
    }
    if(pathexistanderasepath()) {
        if(pathexistanderasepath()) cout << 2 << endl;
        else cout << 1 << endl;
    } else cout << 0 << endl;
}