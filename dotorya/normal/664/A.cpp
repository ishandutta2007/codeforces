#include <stdio.h>

char in1[1050];
char in2[1050];
int main() {
  int i, j;
  scanf("%s %s", in1, in2);
  for(i = 0; in1[i] != 0 && in2[i] != 0; i++) if(in1[i] != in2[i]) break;
  if(in1[i] != in2[i]) printf("1\n");
  else printf("%s\n", in1);
  return 0;
}