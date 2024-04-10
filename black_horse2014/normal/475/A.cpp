#include <cstdio>

char bus[7][50] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};

int x[35], y[35];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int i, k;
    
    for (i = 0; i < 34; i++) {
        if (i < 4) {
            x[i] = i + 1;
            y[i] = 1;
        }
        else {
            x[i] = (i - 4) % 3 + 1;
            if (x[i] == 3) x[i]++;
            y[i] = (i - 1) / 3 * 2 + 1;
        }
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++) bus[x[i]][y[i]] = 'O';
    
    for (i = 0; i < 6; i++) puts(bus[i]);
    return 0;
}