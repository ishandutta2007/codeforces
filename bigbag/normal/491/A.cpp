// a b c d e f g h i j k l m n o p q r s t u v w x y z
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// 1 2 3 4 5 6 7 8 9 0
// ! @ # $ % ^ & * ( ) - _ = + ; : ' " \ / ? , . < > { } [ ] |
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1111111111;

int a, b, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    n = a + b + 1;
    int st = n - a;
    for (int i = st; i <= n; ++i) {
        cout << i << " ";
    }
    for (int i = st - 1; i > 0;--i) {
        cout << i << " ";
    }
    return 0;
}