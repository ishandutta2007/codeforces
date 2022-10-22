#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
int main () {
	int r,c;
	scanf ("%d %d",&r,&c);
	if(r==1&&c==1) return !printf ("0\n");
	if (r==1||c==1) {
		for (int i = 1; i <= max(r,c); i++) printf ("%d%c",i+1," \n"[c==1]);
		return 0;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (j == 1) printf ("%d ",i+1);
			else printf ("%d ",(i + 1) * (j + r));
		} 
		printf ("\n");
	}
	return 0;
}