#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

struct vertex {
    int parent, op, ok;
    vector <int> child;
    int ii, jj;
};

const int max_q = 100000, max_n = 1000;
int n, m, q, ans[max_q+1], a;
bool ms[max_n][max_n];
vertex tr[max_q+1];

void dfs(int v)
{
    int mm = ms[tr[v].ii][tr[v].jj], i, j;
    if (tr[v].op == 1&&mm == 0) {
        a++;
        ms[tr[v].ii][tr[v].jj] = 1;
        tr[v].ok = 1;
    }
    if (tr[v].op == 1&&mm == 1) {
        ms[tr[v].ii][tr[v].jj] = 1;
        tr[v].ok = 0;
    }
    if (tr[v].op == 2&&mm == 0) {
        ms[tr[v].ii][tr[v].jj] = 0;
        tr[v].ok = 0;
    }
    if (tr[v].op == 2&&mm == 1) {
        a--;
        ms[tr[v].ii][tr[v].jj] = 0;
        tr[v].ok = 1;
    }
    if (tr[v].op == 3) {
        for (j = 0; j<m; j++) {
            if (ms[tr[v].ii][j] == 0) {
                ms[tr[v].ii][j] = 1;
                a++;
            }
            else {
                ms[tr[v].ii][j] = 0;
                a--;
            }
        }
    }
    ans[v] = a;
    for (i = 0; i<tr[v].child.size(); i++) {
        dfs(tr[v].child[i]);
    }
    if (tr[v].ok&&(tr[v].op == 1||tr[v].op == 2)) {
        mm = ms[tr[v].ii][tr[v].jj];
        if (mm == 0) {
            ms[tr[v].ii][tr[v].jj] = 1;
            a++;
        }
        else
        {
            ms[tr[v].ii][tr[v].jj] = 0;
            a--;
        }
    }
    if (tr[v].op == 3) {
        for (j = 0; j<m; j++) {
            if (ms[tr[v].ii][j] == 0) {
                ms[tr[v].ii][j] = 1;
                a++;
            }
            else {
                ms[tr[v].ii][j] = 0;
                a--;
            }
        }
    }
}

int main()
{
/*    ofstream fout;
    fout.open("out.txt");
    ifstream fin;
    fin.open("in.txt"); */
    int i, j, tp, iii, jjj, k;
    cin >> n >> m >> q;
    for (i = 1; i<=q; i++) {
        cin >> tp;
        if (tp<4) {
            tr[i].parent = i-1;
            tr[i-1].child.push_back(i);
            tr[i].op = tp;
        }
        if (tp == 1||tp == 2) {
            cin >> iii >> jjj;
            tr[i].ii = iii - 1;
            tr[i].jj = jjj - 1;
        }
        if (tp == 3) {
            cin >> iii;
            tr[i].ii = iii - 1;
        }
        if (tp == 4) {
            cin >> k;
            tr[i].parent = k;
            tr[k].child.push_back(i);
            tr[i].op = 0;
        }
    }
 /*   for (i = 1; i<=q; i++) {
        fout << "vertex " << i << endl;
        fout << "parent " << tr[i].parent << endl;
    } */
    for (i = 0; i<max_n; i++) {
        for (j = 0; j<max_n; j++) {
            ms[i][j] = 0;
        }
    }
    a = 0;
    for (i = 0; i<tr[0].child.size(); i++) {
        dfs(tr[0].child[i]);
    }
    for (i = 1; i<=q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}