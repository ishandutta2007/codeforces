#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+50;
int a[maxn],b[maxn];
priority_queue<int> pq;
int sum;
int n,k1,k2,k;
int main(){
    cin>>n>>k1>>k2;
    int k = k1+k2;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        cin>>b[i];
        b[i] = abs(b[i]-a[i]);
        pq.push(b[i]);
        sum+=b[i];
    }
    if (sum==k){
        cout<<0<<endl;
        return 0;
    }else if (sum<k){
        k-=sum;
        if (k&1){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
        return 0;
    }
    while(k--){
        int temp = pq.top();
        pq.pop();
        pq.push(temp-1);
    }
    long long ans =0;
    while (!pq.empty()){
        int temp = pq.top();
        ans+=1LL*temp*temp;
        pq.pop();
    }
    cout<<ans<<endl;
    return 0;
}