#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[200007];

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    n++;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int v = -1;
    for (int i = 0; i < n - 1; i++) if (a[i] > 1 && a[i + 1] > 1){
    	v = i;
    	break;
    }
    if (v == -1) cout << "perfect", exit(0);
    cout << "ambiguous\n";
    int last = 0;
    int sz = 1;
    for (int i = 0; i < n; i++){
    	for (int s = 0; s < a[i]; s++) cout << last << ' ', sz++;
    	last = sz - 1;
    }
    cout << endl;
    last = 0;
    sz = 1;
    for (int i = 0; i < n; i++){
    	if (i == v + 1){
    		cout << last - 1 << ' ';
    		a[i]--;
    		sz++;
    	}
    	for (int s = 0; s < a[i]; s++) cout << last << ' ', sz++;
    	last = sz - 1;
    }
}