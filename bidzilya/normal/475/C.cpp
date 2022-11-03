#include <cstdio>
#include <iostream>
#include <utility>
#include <cassert>
using namespace std;

const int max_n = 1e3 + 10;

int n, m;
char s[max_n][max_n];
int sx, sy;

pair<int, int> get_start_pos()
{
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (s[i][j] == 'X') {
                return make_pair(i, j);
            }
        }
    }
    assert(false);
}

int answer;
int used[max_n][max_n];

bool check_sizes(int size_x, int size_y)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            used[i][j] = 0;
        }
    }
    for (int i = sx; i < sx + size_x; ++i) {
        for (int j = sy; j < sy + size_y; ++j) {
            used[i][j] = 1;
        }
    }
    int x = sx;
    int y = sy;
    while (true) {
        if (x + size_x < n && s[x + size_x][y] == 'X') {
            for (int j = y; j < y + size_y; ++j) {
                used[x + size_x][j] = 1;
            }
            ++x;
        } else if (y + size_y < m && s[x][y + size_y] == 'X') {
            for (int i = x; i < x + size_x; ++i) {
                used[i][y + size_y] = 1;
            }
            ++y;
        } else {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (used[i][j] && s[i][j] == '.') {
                return false;
            }
            if (!used[i][j] && s[i][j] == 'X') {
                return false;
            }
        }
    }
    return true;
}

void recalc_answer(int size_x, int size_y)
{
    if (check_sizes(size_x, size_y)) {
        if (answer == -1 || size_x * size_y < answer) {
            answer = size_x * size_y;
        }
    }
}

void try_right()
{
    int size_x, size_y;
    size_x = 1;
    while (sx + size_x < n && s[sx + size_x][sy] == 'X') {
        ++size_x;
    }
    if (sx + size_x == n) {
        recalc_answer(size_x, 1);
        return ;
    }
    int y = sy;
    while (y + 1 < m && s[sx][y + 1] == 'X') {
        ++y;
    }
    if (s[sx + size_x][y] == 'X') {
        size_y = 1;
        while (y - 1 >= sy && s[sx + size_x][y - 1] == 'X') {
            ++size_y;
            --y;
        }
        recalc_answer(size_x, size_y);
    } else {
        recalc_answer(size_x, 1);
    }
}

void try_down()
{
    int size_x, size_y;
    size_y = 1;
    while (sy + size_y < m && s[sx][sy + size_y] == 'X') {
        ++size_y;
    }
    if (sy + size_y == m) {
        recalc_answer(1, size_y);
        return ;
    }
    int x = sx;
    while (x + 1 < n && s[x + 1][sy] == 'X') {
        ++x;
    }
    if (s[x][sy + size_y] == 'X') {
        size_x = 1;
        while (x - 1 >= sx && s[x - 1][sy + size_y] == 'X') {
            ++size_x;
            --x;
        }
        recalc_answer(size_x, size_y);
    } else {
        recalc_answer(1, size_y);
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s\n", s[i]);
    }
    
    pair<int, int> temp = get_start_pos();
    sx = temp.first;
    sy = temp.second;
    
    answer = -1;
    
    try_right();
    try_down();

    printf("%d\n", answer);
    
    return 0;
}