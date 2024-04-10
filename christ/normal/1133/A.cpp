#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
    int a,b;
	scanf ("%d:%d",&a,&b);
	int t1 = a*60+b;
	scanf ("%d:%d",&a,&b);
	int t2 = a*60+b;
	int tm = (t1+t2)/2;
	printf ("%02d:%02d",tm/60,tm%60);
    return 0;
}