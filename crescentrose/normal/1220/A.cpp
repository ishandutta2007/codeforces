#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
int n;
int sum[26];
int main() {
    scanf("%d", &n);
    while (n --) {
        char c;
        scanf(" %c", &c);
        sum[c - 'a'] ++;
    }

    while (sum['o' - 'a'] && sum['n' -'a' ] && sum['e' - 'a']){
        printf("1 ");
        sum['o' - 'a'] --, sum['n' -'a' ]-- , sum['e' - 'a']--;
    }
    while (sum['z' - 'a'] && sum['e' -'a' ] && sum['r' - 'a'] && sum['o' - 'a']){
        printf("0 ");
        sum['z' - 'a'] --, sum['e' -'a' ] --, sum['r' - 'a'] --, sum['o' - 'a']--;
    }
    return 0;
}