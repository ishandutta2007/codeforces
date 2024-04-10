#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 3e5+3, MOD = 1e9+7;
ll psa[MN];
int bit[MN], ex[MN];
vector<int> xs;
int getx (int x) {return lower_bound(all(xs),x)-xs.begin()+1;}
void inc (int i) {
	++ex[i];
	for (;i<MN;i+=i&-i)
		++bit[i];
}
void dec (int i) {
	--ex[i];
	for (;i<MN;i+=i&-i)
		--bit[i];
}
int query (int i) {
	int ret = 0;
	for (;i;i^=i&-i)
		ret += bit[i];
	return ret;
}
ll go; int K;
int getkth (int k){
    int pos=0, num=0, i=131072,ret=1e9;
    for(;i>=1;i>>=1){
        if(num+bit[pos+i]<k){
            num+=bit[pos+i];
            pos+=i;
        }
        else if(ex[pos+i]&&num+bit[pos+i]>=k){
            ret = pos+i;
        }
    }
    return ret==1e9?-1:ret;
}
void add (int x) {
	if (!K) return;
	int cmp = getx(x);
	int curk = getkth(K);
	if (curk == -1) {
		go += x;
	} else if (cmp < curk) {
		go -= xs[curk-1];
		go += x;
	}
	inc(cmp);
}
void remove (int x) {
	if (!K) return;
	int cmp = getx(x);
	int curk = getkth(K);
	if (curk == -1 || cmp <= curk) {
		int nxt = getkth(K+1);
		go -= x;
		if (nxt != -1) go += xs[nxt-1];
	}
	dec(cmp);
}
int main() {
	int n,len;
	scanf ("%d %d",&n,&len);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		if (i) psa[i] = psa[i-1];
		scanf ("%d",&a[i]); xs.push_back(a[i]); xs.push_back(-a[i]);
		psa[i] += a[i];
	}
	sort(all(xs)); xs.erase(unique(all(xs)),xs.end());
	scanf ("%d",&K); ll ret = 0;
	for (int i = 0; i < len; i++) if (a[i] < 0) add(a[i]);
	ret = abs(psa[len-1] - (go *2));
	for (int i = len; i < n; i++) {
		if (a[i-len] < 0) remove(a[i-len]);
		if (a[i] < 0) add(a[i]);
		ret = max(ret,abs(psa[i]-psa[i-len]-(go*2)));
	}
	for (int i = 0; i < n; i++) a[i] = -a[i], psa[i] = -psa[i];
	memset(bit,0,sizeof bit); go = 0; memset(ex,0,sizeof ex);
	for (int i = 0; i < len; i++) if (a[i] < 0) add(a[i]);
	ret = max(ret,abs(psa[len-1] - (go *2)));
	for (int i = len; i < n; i++) {
		if (a[i-len] < 0) remove(a[i-len]);
		if (a[i] < 0) add(a[i]);
		ret = max(ret,abs(psa[i]-psa[i-len]-(go*2)));
	}
	printf ("%lld\n",ret);
    return 0;
}