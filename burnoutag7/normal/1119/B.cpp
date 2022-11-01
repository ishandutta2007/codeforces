#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll h;
priority_queue<int> pq;
int a[3005];
int b[3005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>h;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pq.push(-a[i]);
        int cnt;
        for(cnt=1;pq.size()>0;cnt++){
            b[cnt]=-pq.top();
            pq.pop();
        }cnt--;
        ll cur1=0,cur2=0;
        for(int j=1;j<=cnt;j+=2){
            cur1+=max(b[j],b[j+1]);
        }
        cur2+=b[1];
        for(int j=2;j<=cnt;j+=2){
            cur2+=max(b[j],b[j+1]);
        }
        if(min(cur1,cur2)>h){
            cout<<i-1<<endl;
            return 0;
        }
        for(int j=1;j<=cnt;j++){
            pq.push(-b[j]);
        }
    }
    cout<<n<<endl;

    return 0;
}