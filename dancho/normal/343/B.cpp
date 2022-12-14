#include <cstdio>
#include <cstring>

int n;
char s[1<<20];

int stop = 0;
char st[1<<20];

int main() {
  scanf( "%s", s );
  n = strlen( s );
  stop = 0;
  for (int i = 0; i < n; ++i) {
    int fl = 0;
    while ( stop && st[stop] == s[i] )
    {
      fl = 1;
      stop--;
    }
    if ( !fl )
      st[++stop] = s[i];
  }

  printf( "%s\n", stop ? "No" : "Yes" );
  return 0;
}