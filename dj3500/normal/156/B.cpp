#include <cstdio>
#define N 100007
int no[N], yes[N], allno = 0, allyes = 0;
bool znak[N], mogl[N];
int a[N];

int main () {

int n, m;
scanf("%d%d",&n,&m);

for (int i = 1; i <= n; ++i) {
char c; int x;
scanf(" %c%d",&c,&x);
znak[i] = (c == '+');
a[i] = x;
if (znak[i]) {
  ++allyes;
  yes[a[i]]++;
} else {
  ++allno;
  no[a[i]]++;
}
}

int ilemoglo = 0, ileniemoglo = 0;
for (int i = 1; i <= n; ++i) {
int satisf = 0;
satisf += yes[i];
satisf += allno - no[i];
mogl[i] = (satisf == m);
if (mogl[i]) ++ilemoglo;
else ++ileniemoglo;
}

for (int i = 1; i <= n; ++i) {
if (znak[i]) {
if (!mogl[a[i]]) {
printf("Lie\n");
} else if (ilemoglo == 1) {
printf("Truth\n");
} else printf("Not defined\n");
} else {
if (mogl[a[i]]) {
  if (ilemoglo == 1) {
    printf("Lie\n");
  } else printf("Not defined\n");
} else printf("Truth\n");
}
}
}