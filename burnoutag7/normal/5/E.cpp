#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
pair<int,int> a[1000005];
set<int> s;
ll ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    {
        int mx=0;
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            if(a[i].first>a[mx].first)mx=i;
        }
        for(int i=0;i<n;i++){
            a[i].first=-a[i].first;
            a[i].second=(i-mx+n)%n;
        }
    }
    sort(a,a+n);
    for(int i=0,j=0;i<n;i=j){
        while(a[i].first==a[j].first)j++;
        if(!i){
            ans+=(ll)(j-i)*(j-i-1)/2;
        }else{
            int prv=-1,cnt=0,cur;
            for(int k=j;k-->i;){
                cur=*--s.lower_bound(a[k].second);
                if(cur!=prv){
                    prv=cur;
                    ans+=(ll)cnt*(cnt-1)/2+cnt*min((int)s.size(),2);
                    cnt=0;
                }
                cnt++;
            }
            ans+=(ll)cnt*(cnt-1)/2+cnt*min((int)s.size(),2);
        }
        for(int k=i;k<j;k++)s.insert(a[k].second);
    }
    cout<<ans<<endl;

    return 0;
}