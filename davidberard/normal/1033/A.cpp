#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> par;

int N;
void SETUP(int N) {
    par = vector<int>(N, -1);

}
int FIND(int i) {
    if(par[i] == -1) return i;
    par[i] = FIND(par[i]);
    return par[i];
}
void UNION(int i, int j) {
    //cerr << "MERGE " << i << " " << j << endl;
    if(FIND(i) != FIND(j)) {
        par[FIND(i)] = FIND(j);
    }
}

stack<pii> n;
void add_neighbor(int x, int y) {
    if(x < N && y < N && x >= 0 && y >= 0) {
        n.push(pii(x, y));
    }
}
void find_neighbors(int x, int y) {
    add_neighbor(x+1, y+1);
    add_neighbor(x+1, y);
    add_neighbor(x+1, y-1);
    add_neighbor(x, y+1);
    add_neighbor(x, y-1);
    add_neighbor(x-1, y+1);
    add_neighbor(x-1, y);
    add_neighbor(x-1, y-1);
}

int good(int x, int y, int ax, int ay) {
    int X = x-ax, Y = y-ay;
    return (X != 0 && Y != 0 && X-Y != 0 && X+Y != 0);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    SETUP(N*N+N);
    int ax, ay;
    int bx, by;
    int cx, cy;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    --ax; --ay; --bx; --by; --cx; --cy;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            if(good(i, j, ax, ay)) {
                //cerr << " try " << i*N+j << endl;
                find_neighbors(i, j);
                while(!n.empty()) {
                    pii p = n.top();n.pop();
                    if(good(p.first, p.second, ax, ay)) {
                        UNION(p.first*N+p.second, i*N+j);
                    } else {
                        //cerr << "( bad " << p.first*N+p.second <<")" << endl;
                    }
                }
            }
        }
    }
    //cerr << "WANT " << bx*N +by << " " << cx*N+cy << endl;
    if(FIND(bx*N+by) == FIND(cx*N+cy)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}