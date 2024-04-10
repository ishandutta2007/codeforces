#include <stdio.h>
#include <algorithm>
using namespace std;

int in[5];
int main() {
  int i;
  for(i = 0; i < 5; i++) scanf("%d", &in[i]);

  sort(in, in+5);

  int ans = in[0] + in[1] + in[2] + in[3] + in[4];
  if(in[2] == in[3] && in[3] == in[4]) ans = min(ans, in[0] + in[1]);
  if(in[1] == in[2] && in[2] == in[3]) ans = min(ans, in[0] + in[4]);
  if(in[0] == in[1] && in[1] == in[2]) ans = min(ans, in[3] + in[4]);
  if(in[0] == in[1]) ans = min(ans, in[2] + in[3] + in[4]);
  if(in[1] == in[2]) ans = min(ans, in[0] + in[3] + in[4]);
  if(in[2] == in[3]) ans = min(ans, in[0] + in[1] + in[4]);
  if(in[3] == in[4]) ans = min(ans, in[0] + in[1] + in[2]);
  printf("%d\n", ans);
  return 0;
}