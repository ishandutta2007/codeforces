#include <iostream>

using namespace std;
typedef long long ll;

const int N = 1<<20;
int arr[N],tmp[N];
ll inv[21][2];
int qa[21];

//[i,j)
void mergesort(int i, int j, int d) {
  if(!d) return;
  mergesort(i,(i+j)/2,d-1);
  mergesort((i+j)/2,j,d-1);
  for(int k = i; k < j; ++k)
    tmp[k] = arr[k];
  int a=i,b=(i+j)/2;
  int k=i;
  while(k!=j) {
    if(a==(i+j)/2) {
      arr[k++] = tmp[b++];
    } else if(b==j) {
      arr[k++] = tmp[a++];
    } else {
      if(tmp[a] < tmp[b]) {
        inv[d][1] += j-b;
        arr[k++] = tmp[a++];
      } else if(tmp[a] > tmp[b]) {
        inv[d][0]+=(i+j)/2-a;
        arr[k++] = tmp[b++];
      } else {
        int a2=a;
        int b2=b;
        while(a2 < (i+j)/2 && tmp[a2]==tmp[a]) {
          arr[k++]=tmp[a];
          ++a2;
        }
        while(b2 < j && tmp[b2]==tmp[b]) {
          arr[k++]=tmp[b];
          ++b2;
        }
        inv[d][0] += ((i+j)/2-a2) * (b2-b);
        inv[d][1] += (j-b2) * (a2-a);
        a=a2;
        b=b2;
      }
    }
  }
}

int main() {
  int n,m;
  scanf("%d",&n);
  for(int i = 0; i < (1<<n); ++i)
    scanf("%d",arr+i);
  mergesort(0,(1<<n),n);
  scanf("%d",&m);
  while(m--) {
    int q;
    scanf("%d",&q);
    for(int i = q; i >= 0; --i)
      qa[i] = !qa[i];
    ll qr = 0;
    for(int i = 0; i <= n; ++i) {
      qr += inv[i][qa[i]];
    }
    printf("%I64d\n",qr);
  }
}