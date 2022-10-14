#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        lli n;
        lli l,r;
        cin>>n>>l>>r;
        lli cur=0;
        lli cnt=0;
        if(l==n*(n-1)+1){
            printf("%d\n",1);
            continue;
        }
        while(l>cur){
            cnt++;
            cur=cur+(n-cnt)*(lli)2;
        }
        int val=n;
        int actval=n;
        while(cur>l){
            cur--;
            if(cur%2==0){
                val--;
                actval=val;
            }
            else actval=cnt;
        }
        for(lli i=l;i<=r;i++){
            printf("%d ",actval);
            if(actval==cnt){
                if(cnt==n)actval=1;
                else {
                    actval = val;
                }
            }
            else{
                if(actval==n){
                    cnt++;
                    if(cnt==n)cnt=1;
                    val=cnt+1;
                    actval=cnt;
                }
                else{
                    actval=cnt;
                    val++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}