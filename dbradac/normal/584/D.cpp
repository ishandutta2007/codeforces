#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 31700;

int sito[MAX];
vector <int> P;

void Sito()
{
  for (int i=2; i<MAX; i++)
    if (!sito[i]) {
      for (int j=i; j<MAX; j += i)
        sito[j] = 1;
      P.push_back(i);
    }
}

int Prost(int x)
{
  if (x == 1)
    return 0;

  for (int i=0; i<(int) P.size() && P[i] < x; i++)
    if (!(x % P[i]))
      return 0;

  return 1;
}

void Ispis(vector <int> R)
{
  printf("%d\n", (int) R.size());
  for (int i=0; i<(int) R.size(); i++)
    printf("%d ", R[i]);
  printf("\n");
}

int main()
{
  int n;
  vector <int> R;

  scanf("%d", &n);

  Sito();

  for (int i=n; i>=0; i--) {
    if (Prost(i)) {
      R.push_back(i);
      n -= i;
      break;
    }
  }
  
  if (!n)
    Ispis(R);
  else {
    int da=0;
    if (Prost(n)) {
      R.push_back(n);
      da = 1;
    }
      
    if (!da) {
      for (int i=0; i<(int) P.size(); i++) {
        for (int j=0; j<(int) P.size(); j++)
          if (P[i] + P[j] == n) {
            R.push_back(P[i]);
            R.push_back(P[j]);
            da = 1;
            break;
          }
        if (da)
          break;
      }
    }

    Ispis(R);
  }

  return 0;
}