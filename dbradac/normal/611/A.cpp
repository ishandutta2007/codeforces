#include <cstdio>

using namespace std;

int tjed[7] = {52, 52, 52, 52, 53, 53, 52};
int mj[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
  int br;
  char s[10];

  scanf("%d%*s%s", &br, s);

  if (s[0] == 'w')
    printf("%d\n", tjed[br-1]);
  else {
    int ret=0;
    for (int i=0; i<12; i++)
      if (mj[i] >= br)
        ret++;
    printf("%d\n", ret);
  }


  return 0;
}