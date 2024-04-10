#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<18;

char s[MAX]; 
int t;

string Povecaj(string ss)
{
  string rje = "";
  int len = (int) ss.size();

  int dod = 1;

  for (int i=len-1; i>=0; i--) {
    if (dod) {
      if (ss[i] == '9') {
        dod = 1;
        rje.push_back('0');
      }
      else {
        rje.push_back((char) (ss[i] + 1));
        dod = 0;
      }
    }
    else
      rje.push_back(ss[i]);
  }
  if (dod)
    rje.push_back('1');

  reverse(rje.begin(), rje.end());

  return rje;
}

int main()
{
  int len;
  scanf("%d%d %s", &len, &t, s);

  int poz = -1;
  string dec = "";
  string prije = "";

  for (int i=0; i<len; i++) {
    if (s[i] == '.')
      poz = i;
    else if (poz != -1)
      dec.push_back(s[i]);
    else if (poz == -1)
      prije.push_back(s[i]);
  }

  int poz5 = -1;
  for (int i=0; i<(int) dec.size(); i++)
    if (dec[i] >= '5') {
      poz5 = i;
      break;
    }

  if (poz5 != -1) {
    for (; (int) dec.size() > poz5 + 1; dec.pop_back());
    int ima = t;
    for (; ima; ima--) {
      if (dec[poz5] >= '5') {
        dec.pop_back();
        if (!dec.size()) {
          prije = Povecaj(prije);
          break;
        }
        dec[dec.size()-1]++;
        poz5--;
      }
      else
        break;
    }
  }

  printf("%s", prije.c_str());
  if (dec.size())
    printf(".%s\n", dec.c_str());

  return 0;
}