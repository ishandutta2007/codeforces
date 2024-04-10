    #include <algorithm>
    #include <iostream>
    #include <cstring>
    #include <vector>
    #include <cstdio>
    #include <cmath>
    #include <set>
    #define mp make_pair
    #define fi first
    #define se second
    using namespace std;
    const int maxn = 100005;
    int f[maxn];
    int read(){
        int c = 0, f = 1; char ch = getchar();
        while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
        if (ch == '-') f = -1, ch = getchar();
        while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
        return c * f;
    }
    int main(){
        int T = read();
        while (T --){
            int n = read(), k = read();
            if (k % 3){
                if (n % 3)
                    cout << "Alice" << endl;
                else
                    cout << "Bob" << endl;
            }
            else{
                n %= (k + 1);
                if (n == k || n % 3)
                    cout << "Alice" << endl;
                else
                    cout << "Bob" << endl;
            }
        }
    }