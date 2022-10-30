#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int BLOCK = 4000;
const int maxn = 2e5 + 100;
int sum[maxn],st[maxn],en[maxn];
int n;
ll ans;
vector<pair<int,ll> > ID;
vector<int> val(0);
void prework(){
    for (int i = 1,j = 1;i <= n;i++) {
        while (j <= n and sum[j] < sum[i+1]-BLOCK) {
            for (int len=1;len<=(n-j+1)/BLOCK;len++) {
                long long x=j-1ll*len*sum[j]-1;
                ID.push_back(make_pair(len,x));
            }
            j++;
        }
    }
    sort(ID.begin(),ID.end());
    ID.erase(unique(ID.begin(),ID.end()),ID.end());
    val.resize(ID.size(),0);
}
void do_small(int i){
    for (int j = sum[i+1] - 1;j >= sum[i+1] - BLOCK and j>=0;j--) {
        int tlen = sum[i+1]-j;
        int y1=(i-en[j]+1)%(sum[i+1]-j);
        ans+=(i-st[j]+1) / tlen - (i-en[j]+1)/ tlen;
        if (!y1) ans++;
    }
}
void do_large(int i){
    for (int j=1;j * BLOCK <= i;j++) {
        long long x=i - 1ll * j * sum[i+1];
        int id = lower_bound(ID.begin(),ID.end(),make_pair(j,x)) - ID.begin();
        if (id >= 0 and id < ID.size() and ID[id] == make_pair(j,x))ans += val[id];
    }
}
void mainwork(){
    for (int i = 1,j = 1;i <= n;i++) {
        while (j <= n and sum[j] < sum[i+1]-BLOCK) {
            int tlen = n - j + 1;
            for (int len=1;len * BLOCK <= tlen;len++) {
                long long x=j - 1ll * len * sum[j] - 1;
                int id = lower_bound(ID.begin(),ID.end(),make_pair(len,x)) - ID.begin();
                val[id] ++;
            }
            j++;
        }
        do_small(i);
        do_large(i);
    }
}
int main() {
    char buf[maxn];
    scanf("%s",buf+1);
    n=strlen(buf+1);
    for (int i = 1;i <= n;i++) sum[i+1] = sum[i] +(buf[i] == '1');
    for (int i = 1;i <= n;i++) en[sum[i]]=i;
    for (int i = n;i >= 1;i--) st[sum[i]]=i;
    prework();
    mainwork();
    cout<<ans<<endl;
    return 0;
}