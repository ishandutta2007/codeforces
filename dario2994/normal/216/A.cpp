#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#define INF 1000000000
typedef long long int LL; 
typedef unsigned long long int ULL; 
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	cout << a*b+b*c+a*c-a-b-c+1;
}