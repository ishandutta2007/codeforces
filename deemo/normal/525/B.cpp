#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<list>

using namespace std;

string s;
int n , temp;
const int max_n = 2 * 1e5 + 10;
int arr[max_n];
char c;

int main(){
    cin >> s >> n;
    for (int i = 1 ; i <= n ; i++){
	 cin >> temp;
	 arr[temp] += 1;
    }
    int t = 0;
    for (int i = 1 ; i <= ceil(double(s.size()) / 2) ; i++){
	 if ((t + arr[i]) % 2 == 1){
	     c = s[i - 1];
	     s[i - 1] = s[s.size() - i];
	     s[s.size() - i] = c; 
	 }
	 t += arr[i];
    }
    cout << s << endl;
    return 0;
}