#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
char arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> segments;
        int left=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i>0&&arr[i]!=arr[i-1]){
                segments.push_back(i-left);
                left=i;
            }
        }
        if(arr[n-1]==arr[0]){
            if(sz(segments)) {
                segments.push_back(segments[0]+n-left);
                segments.erase(segments.begin());
            }
            else{
                segments.push_back(n);
            }
        }
        else{
            segments.push_back(n-left);
        }
        int ans=0;
        if(sz(segments)==1){
            int len = segments[0];
            while (len > 2) {
                ans++;
                len -= 3;
            }
            if(len!=0&&segments[0]>2)ans++;
        }
        else {
            for (int i = 0; i < sz(segments); i++) {
                int len = segments[i];
                while (len > 2) {
                    ans++;
                    len -= 3;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}