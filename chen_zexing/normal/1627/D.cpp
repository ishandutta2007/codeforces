#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
using namespace std;
int a[1000005],cnt[1000005],oc[1000005];
vector <int> v[1000005];
int main() {
    int T = 1;
    //cin >> T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=1000000;i++)
            for(int j=i;j<=1000000;j+=i)
                v[j].push_back(i);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(auto t:v[a[i]]) cnt[t]++;
        }
        for(int i=1;i<=1000000;i++) {
            int f=cnt[i]>0;
            for (int j = i*2; j <= 1000000; j += i) if(cnt[j]==cnt[i]) f=0;
            ans+=f;
        }
        cout<<ans-n<<endl;
    }
    return 0;
}