   #include <iostream>
    #include <stdio.h>
   #include <set>
   #include <map>
  #include <vector>
  #include <algorithm>
   #include <cassert>
   #include <string.h>
   #include <stdlib.h>
   #include <string>
  #include <time.h>
 #include <math.h>
   #include <utility>
 

  #define taskname ""
  #define inf (((int)1e9)+5)
  #define pb push_back
 

  using namespace std;
 

  long long A[110000], B[110000], k;
 int c;
   bool fl;


  int main() {
    int i, n, cnt, tmp;
    //reopen(taskname".in", "r", stdin);
   //freopen(taskname".out", "w", stdout);
   scanf("%d%I64d", &n, &k);
   for (i=0; i<n; i++)
     scanf("%I64d", &A[i]), B[i+1]=A[i];
    sort(B+1,B+(n+1));
   c=0;
   while (c<n && k>=(B[c+1]-B[c])*((long long)(n-c)))
      k-=(B[c+1]-B[c])*((long long)(n-c)), c++, cerr<<k<<" "<<B[c]<<endl;
    if (c==n && k>0)
    {
     printf("-1\n");
     return 0;
    }
     if (c==n && k==0)
   {
     printf("\n");
      return 0;
   }
   tmp=k/((long long)(n-c));
    k%=((long long)(n-c));
    cnt=(int)k;
   for (i=0; i<n; i++)
     if (A[i]>B[c])
     {
       if (cnt>0)
         cnt--;
       else
       {
        if (fl)
          printf(" ");
          fl=1;
        printf("%d", i+1);
       }
     }
   //printf(" !!!! ");
   cnt=(int)k;
    for (i=0; i<n; i++)
     if (A[i]>B[c] && cnt>0)
      {
        cnt--;
        if (A[i]>B[c]+1+tmp)
        {
         if (fl)
           printf(" ");
          fl=1;
          printf("%d ", i+1);
       }
     }
    printf("\n");
    return 0;
}