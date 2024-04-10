#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,d;
int a[305],b[305],t[305];
ll prv[150005],cur[150005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>d;
    t[0]=1;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>t[i];
    }
    for(int i=m;i>=1;i--){
        t[i]-=t[i-1];
    }
    for(int i=1;i<=m;i++){
        deque<int> q;
        for(int cp=1,pp=1;cp<=n;cp++){
            while(pp<=(ll)t[i]*d+cp&&pp<=n){
                while(!q.empty()&&prv[q.back()]<=prv[pp])q.pop_back();
                q.push_back(pp);
                pp++;
            }
            while(q.front()<cp-(ll)t[i]*d)q.pop_front();
            cur[cp]=prv[q.front()]+b[i]-abs(a[i]-cp);
        }
        swap(cur,prv);
    }
    cout<<*max_element(prv+1,prv+1+n)<<endl;

    return 0;
}