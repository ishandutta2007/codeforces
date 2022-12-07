#include <bits/stdc++.h>

typedef double r64;
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

int n, q, a[1 << 18];

int main() {
  read(n); read(q);
  n = 1 << n; 
  r64 su = 0;
  for (int i = 0; i < n; i++) {
    read(a[i]); su += a[i];
  }
  
  r64 p = n;
  printf("%.8lf\n", su / p);
  while (q--) {
    int x, y; read(x); read(y);
    su -= a[x];
    a[x] = y;
    su += a[x];
    printf("%.8lf\n", su / p);    
  } 
	return 0;
}