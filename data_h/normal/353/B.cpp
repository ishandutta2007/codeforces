#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111;
int n;
struct Node {
    int val, belone, id; 
}p[N * 2];

vector<int> useless;
vector<int> single;

int base = 0, hash[N * 100];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++) {
        scanf("%d", &p[i].val);
        p[i].id = i;
        if (hash[p[i].val] > 0) {
            p[i].belone = 1;
            hash[p[i].val] = -1;
            base++;
        } else if (hash[p[i].val] == -1) {
            useless.push_back(i);
        } else {
            hash[p[i].val] = i;
        }
    }
    for(int i = 1; i <= 2 * n; i++)
        if (hash[p[i].val] > 0) {
            single.push_back(i);
            hash[p[i].val] = -1;
        }
    int cntA = n - base, cntB = n - base, baseA = base, baseB = base;
    for(int i = 0; i < (int)single.size() / 2; i++) {
        p[single[i]].belone = 1;
        cntB--;
        baseB++;
    }
    for(int i = (int)single.size() / 2; i < (int)single.size(); i++) {
        p[single[i]].belone = 0;
        cntA--;
        baseA++;
    }
    for(int i = 0; i < (int)useless.size(); i++) {
        if (cntB > 0)
            p[useless[i]].belone = 1, cntB--;
        else 
            p[useless[i]].belone = 0, cntA--;
    }
    printf("%d\n", baseA * baseB);
    for(int i = 1; i <= 2 * n; i++) {
        printf("%d", p[i].belone + 1);
        if (i < 2 * n)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}