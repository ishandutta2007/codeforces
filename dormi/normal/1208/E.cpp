#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
lli ans[MAXN];
pair<lli,int> deq[MAXN];
int l,r;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,w;
    cin>>n>>w;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        l=0,r=-1;
        lli b;
        int diff=w-a;
        for(int j=0;j<a;j++){
            cin>>b;
            while(l<=r&&deq[r].first<=b)r--;
            deq[++r]={b,j};
            while(deq[l].second<j-diff)l++;
            if(j>=w-a||deq[l].first>0) {
                ans[j] += deq[l].first;
                ans[j + 1] -= deq[l].first;
            }
        }
        int cur=a;
        while(cur<w){
            int ri=deq[l].second+diff+1;
            if(deq[l].first>0) {
                ans[cur] += deq[l].first;
                ans[ri] -= deq[l].first;
            }
            l++;
            cur=ri;
        }
    }
    printf("%lli ",ans[0]);
    for(int i=1;i<w;i++)ans[i]+=ans[i-1],printf("%lli ",ans[i]);
    return 0;
}