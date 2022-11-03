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

int n, c;
int a[100007];
vector<int> was[1000007];

int get(int color, int x){
	int l = -1, r = (int)was[color].size();
	while(l + 1 < r){
		int mm = (l + r) >> 1;
		if (was[color][mm] >= x)
			r = mm;
		else
			l = mm;
	}
	return l + 1;
}

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
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) was[a[i]].pub(i); 

    for (int i = 1; i <= 1000000; i++) if (i != c) {
    	bool f = 1;

    	for (int x : was[i]) if (get(c, x) > get(i, x)){
    		f = 0;
    		break;
    	}

    	if (get(c, n) > get(i, n)) f = 0;

    	if (f) cout << i, exit(0);
    }

    cout << -1;
}