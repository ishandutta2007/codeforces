#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+5;
int main() {
	int n;
	scanf ("%d",&n);
	if (n%4==0) printf ("0\n");
	else if (n%4==1) printf ("1\n");
	else if (n%4==2) printf ("1\n");
	else printf ("0\n");
    return 0;
}