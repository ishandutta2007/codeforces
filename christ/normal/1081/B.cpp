#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+2;
typedef long long ll;
typedef pair<int,int> pii;
#define all(x) (x).begin(),(x).end()
int main() {
    int n;
    scanf ("%d",&n);
    vector<int> a(n);
    vector<int> freq(n);
    vector<int> what(n), taken(n);
    for (auto &au : a) scanf ("%d",&au), ++freq[au];
    for (int i = 0; i < n; i++) what[i] = i+1;
    bool good = 1;
    for (int i = 0; i < n; i++) if (freq[i]){
        good &= freq[i]%(n-i)==0;
    }
    if (!good) return !printf ("Impossible\n");
    printf ("Possible\n");int go = 0;
    for (int i = 0; i < n; i++) {
        if (taken[a[i]]%(n-a[i])==0) what[a[i]] = ++go;
        printf ("%d ",what[a[i]]);
        taken[a[i]]++;
    }
    printf ("\n");
    return 0;
}