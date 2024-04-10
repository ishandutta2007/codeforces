#include<iostream>
#include<algorithm>
#include<cstring>
 
using namespace std;
 
const int N = 100010; 
 
int n, t, m;
int x;
 
int main () {
    scanf ("%d",&t);
    
    while (t--){
    	scanf("%d%d", &n, &m);
    	string s(m,'B');
    	while (n--){
    		cin >> x;
    		x --;
    		x = min(x, m-1-x);
    		if (s[x] == 'B')	s[x] = 'A';
    		else s[m-x-1] = 'A';
		}
		cout << s <<endl;
	}
	
    return 0;
}