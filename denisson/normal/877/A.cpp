#include <bits/stdc++.h>
        
using namespace std;
        
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

string s;
string a[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

int main(){ 
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //freopen("heavy.in", "r", stdin);
    //freopen("heavy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    int cnt = 0;

    for (int i = 0; i < s.size(); i++){
    	for (int j = 0; j < 5; j++){
    		bool f = 1;
    		for (int g = 0; g < a[j].size(); g++){
    			if (i + g >= s.size()){
    				f = 0;
    				break;
    			}
    			if (s[i + g] != a[j][g]) f = 0;
    		}
    		if (f) cnt++;
    	}
    }

    if (cnt == 1) cout << "YES";
    else cout << "NO";
}