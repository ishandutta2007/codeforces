#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;



int main() {	
	int a;
	scanf("%d",&a);
	if(a == 1) {
		printf("1 1\n1\n");
	}
	else printf("%d 2\n1 2\n",a*2-2);
}