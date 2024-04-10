#include<bits/stdc++.h>
using namespace std;
const int MN = 1e5+2;
typedef pair<int,int> pii;
int p[MN], sz[MN];
bool done[MN];
map<int,int> cnt;
int find (int n) {return p[n]==n?n:p[n]=find(p[n]);}
void merge (int a, int b) {
    if((a=find(a))==(b=find(b))) return;
    p[a] = b;
    sz[b] += sz[a];
}
int main() {
    int n,loc=0,k=-1;
    scanf ("%d",&n);
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) scanf ("%d",&arr[i].first), arr[i].second = i;
    if (n == 1) return !printf ("%d\n",arr[0].first+1);
    sort(arr.begin(),arr.end());
    for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
    for (auto &a : arr) {
        if (a.second && done[a.second-1]) {
            if(!(--cnt[sz[find(a.second-1)]])) cnt.erase(sz[find(a.second-1)]);
            merge(a.second,a.second-1);
        }
        if (a.second < n-1 && done[a.second+1]) {
            if (!(--cnt[sz[find(a.second+1)]])) cnt.erase(sz[find(a.second+1)]);
            merge(a.second,a.second+1);
        }
        ++cnt[sz[find(a.second)]];
        done[a.second]=1;
        if (cnt.size() == 1 && cnt.begin()->second > loc) {
            loc = cnt.begin()->second;
            k = a.first+1;
        }
    }
	return !printf("%d\n",k);
}