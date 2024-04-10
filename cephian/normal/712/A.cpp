#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int a[100005]={0},n;

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d",a+i);
	for(int i = 0; i < n; ++i)
		printf("%d ",a[i]+a[i+1]);
	printf("\n");
	return 0;
}