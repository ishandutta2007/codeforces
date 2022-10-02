#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

string a,b;
int uno1,uno2;

int main(){
	cin >> a >> b;
	for(int i=0;i<int(a.size());i++)if(a[i]=='1')uno1++;
	for(int i=0;i<int(b.size());i++)if(b[i]=='1')uno2++;
	if(uno1%2)uno1++;
	if(uno1>=uno2)cout << "YES\n";
	else cout << "NO\n";
}