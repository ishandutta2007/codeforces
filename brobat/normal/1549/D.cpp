#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007

long long *st;
  
  
/*  A recursive function to get gcd of given
    range of array indexes. The following are parameters for
    this function.
  
    st    --> Polong longer to segment tree
    si --> Index of current node in the segment tree. Initially
               0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment
                 represented by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
long long findGcd(long long ss, long long se, long long qs, long long qe, long long si)
{
    if (ss>qe || se < qs)
        return 0;
    if (qs<=ss && qe>=se)
        return st[si];
    long long mid = ss+(se-ss)/2;
    return __gcd(findGcd(ss, mid, qs, qe, si*2+1),
               findGcd(mid+1, se, qs, qe, si*2+2));
}
  
//Finding The gcd of given Range
long long findRangeGcd(long long ss, long long se, long long arr[],long long n)
{
    if (ss<0 || se > n-1 || ss>se)
    {
        return -1;
    }
    return findGcd(0, n-1, ss, se, 0);
}
  
// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st
long long constructST(long long arr[], long long ss, long long se, long long si)
{
    if (ss==se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    long long mid = ss+(se-ss)/2;
    st[si] = __gcd(constructST(arr, ss, mid, si*2+1),
                 constructST(arr, mid+1, se, si*2+2));
    return st[si];
}
  
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
long long *constructSegmentTree(long long arr[], long long n)
{
   long long height = (long long)(ceil(log2(n)));
   long long size = 2*(long long)pow(2, height)-1;
   st = new long long[size];
   constructST(arr, 0, n-1, 0);
   return st;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    long long t; cin >> t; while(t--)
{
    // delete[] st;
    // Code goes here
    long long n;
    cin >> n;
    long long grr[n];
    forn(i, n) cin >> grr[i];
    if(n==1) {
        cout << 1 << endl;
        continue;
    }
    long long arr[n];
    forn(i, n-1) arr[i] = abs(grr[i+1] - grr[i]);
    // forn(i, n-1) cout << arr[i] << " ";
    // cout << endl;
    // Two pointers
    long long ans = 1;
    long long l = 0;
    long long r = 1;
    // Check for all differences of 1!!!!
    bool allOne = true;
    forn(i, n-1) if(arr[i]!=1) allOne = false;
    if(allOne) {
        cout << 1 << endl;
        // cout << "LOL";
    }
    else {
    constructSegmentTree(arr, n-1);
    while((r < n - 1) && (l < n-2)) {
        if(l==r) r+=1;
        else if(findRangeGcd(l, r, arr, n-1)==1) {
            ans = max(ans, r - l);
            l += 1;
        }
        else {
            r += 1;
        }
    }
    ans = max(ans, r - l);
    cout << ans + 1 << endl;
}}
    return 0;
}