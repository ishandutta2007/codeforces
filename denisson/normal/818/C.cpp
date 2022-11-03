#include <bits/stdc++.h>
     
using namespace std;
     
typedef unsigned long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
    
 
/*const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }*/

int n, m, d;
pair<pair<int, int>, pair<int, int> > a[100007];
int need[4];
int ans[100007][4];

const bool is_testing = 0;
int main() { 
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    } else {
        //freopen("cpr.in", "r", stdin);
        //freopen("cpr.out", "w", stdout);
    }
    scanf("%d %d %d", &d, &n, &m);
    for (int i = 0; i < d; i++) scanf("%d %d %d %d", &a[i].x.x, &a[i].y.x, &a[i].x.y, &a[i].y.y);
    for (int i = 0; i < 4; i++) scanf("%d", &need[i]);

   	vector<int> t;

    for (int i = 0; i < d; i++){
    	t.pub(min(a[i].x.x, a[i].x.y));
    }

    sort(all(t));

    for (int i = 0; i < d; i++){
    	int pos = max(a[i].x.x, a[i].x.y);
    	int l = -1, r = d;
    	while(l + 1 < r){
    		int mm = (l + r) >> 1;
    		if (t[mm] >= pos)
    			r = mm;
    		else
    			l = mm;
    	}
    	if (min(a[i].x.x, a[i].x.y) < max(a[i].x.x, a[i].x.y)) l--;
    	ans[i][0] = l + 1;
    }

    // 
    t.clear();

    for (int i = 0; i < d; i++){
    	t.pub(max(a[i].x.x, a[i].x.y));
    }

    sort(all(t));

    for (int i = 0; i < d; i++){
    	int pos = min(a[i].x.x, a[i].x.y);
    	int l = -1, r = d;
    	while(l + 1 < r){
    		int mm = (l + r) >> 1;
    		if (t[mm] <= pos)
    			l = mm;
    		else
    			r = mm;
    	}
    	if (max(a[i].x.x, a[i].x.y) > min(a[i].x.x, a[i].x.y)) r++;
    	ans[i][1] = d - r;
    }

    //
    t.clear();
    for (int i = 0; i < d; i++){
    	t.pub(min(a[i].y.x, a[i].y.y));
    }

    sort(all(t));

    for (int i = 0; i < d; i++){
    	int pos = max(a[i].y.x, a[i].y.y);
    	int l = -1, r = d;
    	while(l + 1 < r){
    		int mm = (l + r) >> 1;
    		if (t[mm] >= pos)
    			r = mm;
    		else
    			l = mm;
    	}
    	if (min(a[i].y.x, a[i].y.y) < max(a[i].y.x, a[i].y.y)) l--;
    	ans[i][2] = l + 1;
    }

    // 
    t.clear();

    for (int i = 0; i < d; i++){
    	t.pub(max(a[i].y.x, a[i].y.y));
    }

    sort(all(t));

    for (int i = 0; i < d; i++){
    	int pos = min(a[i].y.x, a[i].y.y);
    	int l = -1, r = d;
    	while(l + 1 < r){
    		int mm = (l + r) >> 1;
    		if (t[mm] <= pos)
    			l = mm;
    		else
    			r = mm;
    	}
    	if (max(a[i].y.x, a[i].y.y) > min(a[i].y.x, a[i].y.y)) r++;
    	ans[i][3] = d - r;
    }

    for (int i = 0; i < d; i++){
    	bool f = 1;
    	for (int j = 0; j < 4; j++) if (need[j] != ans[i][j]) f = 0;
    	if (f) cout << i + 1, exit(0);
    }
    cout << -1;
}