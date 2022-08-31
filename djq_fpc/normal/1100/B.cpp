#include <bits/stdc++.h>
using namespace std;

const int maxn=int(1e5)+100;

int n, m;
int cnt[maxn];

int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // edx@2
  signed int v4; // eax@6
  int v6; // [sp+10h] [bp-10h]@2
  int v7; // [sp+14h] [bp-Ch]@1
  signed int i; // [sp+18h] [bp-8h]@1
  signed int j; // [sp+1Ch] [bp-4h]@5

  scanf("%d%d", &m, &n);
  v7 = 0;
  for ( i = 1; i <= n; ++i )
  {
    scanf("%d", &v6);
    v3 = cnt[v6];
    cnt[v6] = v3 + 1;
    if ( v3 == 0 )
      ++v7;
    if ( v7 == m )
    {
      putchar(49);
      for ( j = 1; j <= m; ++j )
      {
        v4 = j;
        --cnt[j];
        if ( cnt[v4] == 0 )
          --v7;
      }
    }
    else
    {
      putchar(48);
    }
  }
  return 0;
}