#include <bits/stdc++.h>
          
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double   
//ANKETA

int n;
int a[200007];
pair<int, int> b[200007];
int ans[200007];

int main(){ 
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);       
    //freopen("output2.txt", "w", stdout);
    //freopen("heavy.in", "r", stdin);
    //freopen("heavy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n; j++) cin >> b[j].x, b[j].y = j;
    sort(a, a + n);
	reverse(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++) ans[b[i].y] = a[i];
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}