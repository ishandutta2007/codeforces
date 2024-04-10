#include <bits/stdc++.h>
                      
using namespace std;
              
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

struct vert{
	int sz;
	int to[2];
	vert() { to[0] = to[1] = -1; sz = 0; }
};

vert t[300007 * 30];
int sz = 1;

int n;
int a[300007];

void add(int x){
	int v = 0;	
	for (int i = 29; i >= 0; i--){
		int b = (x >> i) & 1;
		if (t[v].to[b] == -1) t[v].to[b] = sz++;
		t[v].sz++;
		v = t[v].to[b];
	}
	t[v].sz++;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	add(x);
    }
    for (int i = 0; i < n; i++){
    	int v = 0;
    	int ans = 0;
    	for (int j = 29; j >= 0; j--){
    		t[v].sz--;
    		int b = (a[i] >> j) & 1;
    		if (t[v].to[b] != -1 && t[t[v].to[b]].sz != 0){
    			v = t[v].to[b];
    		} else {
    			v = t[v].to[b ^ 1];
    			ans ^= (1 << j);
    		}
    	}
    	t[v].sz--;
    	cout << ans << ' ';
    }
}