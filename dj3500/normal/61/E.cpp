#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(t)while(t--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
template<typename T,typename TT> inline ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> inline ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.sz)s<<t[i]<<" ";return s; }
inline void pisz(int n) { printf("%d\n",n); }

ll  _mergeSort(pii arr[], pii temp[], int left, int right);
ll merge(pii arr[], pii temp[], int left, int mid, int right);
pii a[1000002];
int m[1000002],m2[1000002];
 

/* This function sorts the input array and returns the
   number of inversions in the array */
ll mergeSort(pii arr[], int array_size)
{
   pii *temp = (pii *)malloc(sizeof(pii)*array_size);
   return _mergeSort(arr, temp, 0, array_size - 1);
}
 
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
ll _mergeSort(pii arr[], pii temp[], int left, int right)
{
   int mid;
   ll inv_count = 0;
   if (right > left)
   {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
      for each of the parts */
      mid = (right + left)/2;
 
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
      inv_count  = _mergeSort(arr, temp, left, mid);
      inv_count += _mergeSort(arr, temp, mid+1, right);
 
      /*Merge the two parts*/
      inv_count += merge(arr, temp, left, mid+1, right);
   }
   return inv_count;
}
 
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
ll merge(pii arr[], pii temp[], int left, int mid, int right)
{
//   DBG(left)DBG(mid)DBG(right)
   int i, j, k;
   ll inv_count = 0;
 
   i = left; /* i is index for left subarray*/
   j = mid;  /* i is index for right subarray*/
   k = left; /* i is index for resultant merged subarray*/
   int poten = 0;
   while ((i <= mid - 1) && (j <= right))
   {
      if (arr[i] <= arr[j])
      {
         temp[k++] = arr[i++];
         m2[arr[i-1].second] += poten;
      }
      else
      {
         temp[k++] = arr[j++];
 
         /*this is tricky -- see above explanation/diagram for merge()*/
         m[arr[j-1].second] += mid - i;
         ++poten;
      }
   }
 
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
   while (i <= mid - 1) {
      temp[k++] = arr[i++];
      m2[arr[i-1].second] += poten;
   }
 
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
   while (j <= right) {
      temp[k++] = arr[j++];
//         DBG(arr[j-1])
  //       DBG(m[arr[j-1]])
    //     DBG(mid-i)
         m[arr[j-1].second] += mid - i;
      //   DBG(m[arr[j-1]])
   }
 
   /*Copy back the merged elements to original array*/
   for (i=left; i <= right; i++)
      arr[i] = temp[i];
 
   return inv_count;
}
 
int main () {
   wez(n)
   FOR(i,n) {
      wez(x)
      a[i] = mp(x,i);
      m[i] = m2[i] = 0;
   }
   
   mergeSort(a,n);
   
   ll w = 0;
   FOR(i,n) {
      w += (ll)m[i] * m2[i];
   }
   cout << w << endl;
}