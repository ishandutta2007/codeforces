#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
lli arr[MAXN];
map<lli,lli> am;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,k;
    cin>>n>>k;
    lli totsum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        totsum+=arr[i];
        am[arr[i]]++;
    }
    sort(arr,arr+n);
    lli leftam=0;
    lli leftsum=0;
    lli ans=LLONG_MAX;
    for(auto x:am){
        lli needed=k-x.second;
        if(needed<=0){
            printf("0\n");
            return 0;
        }
        lli rightam=n-leftam-x.second;
        lli rightsum=totsum-leftsum-x.first*x.second;
        if(leftam>=needed){
            ans=min(ans,leftam*(x.first-1)-leftsum+needed);
        }
        else{
            ans=min(ans,leftam*(x.first)-leftsum+(rightsum-(rightam)*(x.first+1)+needed-leftam));
        }
        if(rightam>=needed){
            ans=min(ans,rightsum-(rightam)*(x.first+1)+needed);
        }
        else{
            ans=min(ans,rightsum-(rightam)*(x.first)+leftam*(x.first-1)-leftsum+needed-(rightam));
        }
        leftam+=x.second;
        leftsum+=x.first*x.second;
    }
    printf("%lli\n",ans);
    return 0;
}