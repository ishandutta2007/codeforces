#include<bits/stdc++.h>
using namespace std;
int n,cnt1,cnt2,ans;
int main(){
    cin>>n;
    while (n--){
        int temp;
        scanf("%d",&temp);
        if (temp&1)cnt1++;
        else cnt2++;
    }
    ans =0;
    ans += min(cnt1,cnt2);
    cnt1-=ans;
    cnt2-=ans;
    ans+=cnt1/3;
    cout<<ans<<endl;
    return 0;
}