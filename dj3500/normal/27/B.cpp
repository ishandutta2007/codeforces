#include <cstdio>
#include <deque>
#include <cstdlib>
using namespace std;

int wyn[52][52];
int vis[52];
int n,a,b;

void dfs (int v) {
   if (vis[v] == 1) {
      printf("%d %d\n",b,a);
      exit(0);
   }
   if (vis[v] == 2) return;
   // vis[v] == 0
   vis[v] = 1;
   
   for (int i = 1; i <= n; ++i) {
      if (wyn[v][i]) {
         dfs(i);
      }
   }
   
   vis[v] = 2;
}


int main () {
   scanf("%d",&n);
   int m = n*(n-1)/2 - 1;
   
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         wyn[i][j] = 0;
      }
   }
   
   for (int i = 0; i < m; ++i) {
      scanf("%d %d", &a, &b);
      wyn[a][b] = 1;
   }
   
   for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
         if (wyn[i][j] == 0 && wyn[j][i] == 0) {
            a=i;
            b=j;
         }
      }
   }
   wyn[a][b] = 1; // sprawdzamy
   
   for (int i = 1; i <= n; ++i) {
      vis[i] = 0; // white
   }
   
   for (int i = 1; i <= n; ++i) {
      dfs(i);
   }
   
   printf("%d %d\n",a,b);
   return 0;
}