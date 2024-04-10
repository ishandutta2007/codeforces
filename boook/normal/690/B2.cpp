#include <bits/stdc++.h>
using namespace std;
//#define DEBUG
#define ll long long
#define INF 0x3f3f3f3f
#define INF16 16000000000000000LL
#define INF18 1000000000000000000LL
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mod9 (int)(1e9 + 9)
#define mod7 (int)(1e9 + 7)
#define eps 1e-9
#define mse(x , y) memset(x , y , sizeof(x))
#define ALL(x) x.begin(),x.end()
#define IOS do { ios::sync_with_stdio(0);cin.tie(0); } while (0)

inline ll rit(){
    int key = 1;
    char c = getchar();
    while(!isdigit(c)){
        if(c == '-') key = -1;
        c = getchar();
    }

    ll x = 0;
    while(isdigit(c)){
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * key;
}

/*********default*********/

struct Point{
    int x , y;

    bool operator < (const Point& rhs){
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }

}p[300010] , ch[300010];

Point operator - (const Point &a ,const Point &b){
    return (Point){a.x - b.x, a.y - b.y};
}

int cross(const Point &a ,const Point &b){
    return a.x * b.y - a.y * b.x;
}

int convexHull(int n){
    sort(p, p + n);
    int m = 0;
    for(int i = 0; i < n; i++){
        while(m > 1 && cross(ch[m - 1] - ch[m - 2] , p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }

    int k = m;
    for(int i = n - 2; i >= 0; i--){
        while(m > k && cross(ch[m - 1] - ch[m - 2] , p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }

    if(m > 1) m--;
    return m;
}

int book[510][510];
int a[510][510];
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n) {
        string s;

        memset(book, 0, sizeof(book));
        for(int i = n - 1; i >= 0; i--) {
            cin >> s;
            for(int j = 0; j < n; j++) {
                if(s[j] == '0') {
                    for(int k = 0; k < 4; k++) {
                        int newx = i + dx[k];
                        int newy = j + dy[k];
                        book[newx][newy] = 1;
                    }
                }
            }
        }

        int nn = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(book[i][j] == 0) {
                    p[nn++] = (Point){i, j};
                }
            }
        }

        int num = convexHull(nn);
        printf("%d\n", num);

        pair<int, int> pr = make_pair(ch[0].y, ch[0].x);
        int pos = 0;

        for(int i = 0; i < num; i++) {
            if(make_pair(ch[i].y, ch[i].x) < pr) {
                pr = make_pair(ch[i].y, ch[i].x);
                pos = i;
            }
        }

        for(int i = 0; i < num; i++) {
            printf("%d %d\n", ch[(i + pos) % num].y, ch[(i + pos) % num].x);
        }
    }
    return 0;
}