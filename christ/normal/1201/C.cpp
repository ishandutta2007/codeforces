#include<bits/stdc++.h>
using namespace std;
int a[200005];
map<int,int> freq;
int main () {
    int n,k;
    scanf ("%d %d",&n,&k);
    for (int i = 0; i < n; i++) scanf ("%d",&a[i]);
    sort(a,a+n);
    for (int i = (n>>1); i < n; i++) freq[a[i]]++;
    int med = a[(n>>1)];
    for (int i = (n>>1), cnt = 0; i < n && cnt < k; i++) {
      if (i < n-1 && a[i] == a[i+1]) continue;
      int times = (k-cnt)/freq[a[i]];
      if (i < n-1) times = min(times,(a[i+1]-a[i]));
      cnt += times * freq[a[i]];
      med += times;
      if (i < n-1) freq[a[i+1]] += freq[a[i]];
    }
    printf ("%d\n",med);
    return 0;
}